#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int v[N],w[N],s[N],f[N];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            for(int k=0;k<=s[i]&&k*w[i]<=j;k++){
                f[j]=max(f[j],f[j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<f[m];
    return 0;
}