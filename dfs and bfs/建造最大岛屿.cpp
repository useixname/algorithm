#include<bits/stdc++.h>
using namespace std;
const int N=110;
int net[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int a[N][N],s[N],vis[N];
int n,m,cnt=2,sum,ans;
bool flag=true;

void dfs(int x,int y){
    a[x][y]=cnt;
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==1){
            sum++;
            dfs(tx,ty);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                flag=false;
            }
        }
    }
    if(flag){
        cout<<n*m;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1){
                sum=1;
                dfs(i,j);
                s[cnt]=sum;
                cnt++;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%3d",a[i][j]);
    //     }
    //     printf("\n");
    // }
    // cout<<cnt<<'\n';
    // cout<<s[60]<<'\n';
    // for(int i=2;i<=cnt-1;i++){
    //     cout<<s[i]<<" ";
    // }
    // int t1,t2;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(a[i-1][j]==37&&a[i][j+1]==60){
    //             cout<<i<<" "<<j<<'\n';
    //             t1=i;
    //             t2=j;
    //             break;
    //         }
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!a[i][j]){
                memset(vis,0,sizeof(vis));
                int t=1;
                for(int k=0;k<4;k++){
                    int tx=i+net[k][0],ty=j+net[k][1];
                    if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]!=0&&!vis[a[tx][ty]]){
                        vis[a[tx][ty]]=1;
                        // cout<<a[tx][ty]<<'\n';
                        // cout<<s[a[tx][ty]]<<'\n';
                        t+=s[a[tx][ty]];
                    }
                }
                ans=max(ans,t);
            }
        }
    }
    cout<<ans;
    return 0;
}