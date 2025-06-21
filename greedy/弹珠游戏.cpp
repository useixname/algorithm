#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N][N],r[N],c[N];
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            r[i]+=a[i][j];
            c[j]+=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0){
                ans=max(ans,r[i]+c[j]);
            }
        }
    }
    cout<<ans;
    return 0;
}