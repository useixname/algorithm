#include<iostream>
#include<cstring>
using namespace std;

const int N=110;
int T,n,m,cnt;
char map[N][N];

void DFS(int x,int y){
    if(y>m) x++,y=1;
    if(x>n){
        bool flag=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(map[i][j]>='1' && map[i][j]<='9') flag=false;
        if(flag) cnt++;
        return;
    }
    if(map[x][y]=='*'){
        bool flag=true;
        for(int i=max(x-1,1);i<=min(x+1,n);i++)
            for(int j=max(y-1,1);j<=min(y+1,m);j++)
                if(map[i][j]=='0') flag=false;
        if(flag){
            for(int i=max(x-1,1);i<=min(x+1,n);i++)
                for(int j=max(y-1,1);j<=min(y+1,m);j++)
                    if(map[i][j]!='*') map[i][j]--;
            DFS(x,y+1);
            for(int i=max(x-1,1);i<=min(x+1,n);i++)
                for(int j=max(y-1,1);j<=min(y+1,m);j++)
                    if(map[i][j]!='*') map[i][j]++;
        }
    }
    DFS(x,y+1);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        memset(map,0,sizeof(map));
        cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>map[i][j];
        DFS(1,1);
        if(cnt==1) cout<<"Single"<<endl;
        else cout<<"Multiple"<<endl;
    }
    return 0;
}