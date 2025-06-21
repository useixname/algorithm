#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int f[N],w[210];
bool choice[210][N],vis[210];
int n,m1,m2,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m1>>m2;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m1;j>=w[i];j--){
            if(f[j]<f[j-w[i]]+w[i]){
                f[j]=f[j-w[i]]+w[i];
                choice[i][j]=true;
            }
        }
    }
    ans+=f[m1];
    int now=m1;
    for(int i=n;i>=1;i--){
        if(choice[i][now]){
            vis[i]=true;
            now-=w[i];
        }
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        for(int j=m2;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+w[i]);
        }
    }
    ans+=f[m2];
    cout<<ans;
    return 0;
}// 15 10 6 3 1 0