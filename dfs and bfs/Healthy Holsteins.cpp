#include<bits/stdc++.h>
using namespace std;
const int N=30;
int a[N],vis[N],b[N][N],c[N],ret[N],d[N];
int v,g,ans=N;

bool chk(){
    for(int i=1;i<=v;i++){
        if(c[i]<a[i]) return false;
    }
    return true;
}

void dfs(int u,int step){
    if(u>g) return;
    if(step>ans) return;
    if(chk()){
        if(ans>step){
            ans=step;
            for(int i=0;i<step;i++){
                d[i]=ret[i];
            }
        }
    }
    ret[step]=u+1;
    for(int j=1;j<=v;j++){
        c[j]+=b[u+1][j];
    }
    dfs(u+1,step+1);
    ret[step]=0;
    for(int j=1;j<=v;j++){
        c[j]-=b[u+1][j];
    }
    dfs(u+1,step);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>v;
    for(int i=1;i<=v;i++){
        cin>>a[i];
    }
    cin>>g;
    for(int i=1;i<=g;i++){
        for(int j=1;j<=v;j++){
            cin>>b[i][j];
        }
    }
    dfs(0,0);
    cout<<ans;
    for(int i=0;i<ans;i++){
        cout<<" "<<d[i];
    }
    return 0;
}