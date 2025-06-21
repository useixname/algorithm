#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int f[N],w[N],v[N];
int s,n,d;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s>>n>>d;
    for(int i=1;i<=d;i++){
        cin>>w[i]>>v[i];
    }
    for(int k=1;k<=n;k++){
        memset(f,0,sizeof(f));
        int m=s/1000;
        for(int i=1;i<=d;i++){
            for(int j=w[i]/1000;j<=m;j++){
                f[j]=max(f[j],f[j-w[i]/1000]+v[i]);
            }
        }
        s+=f[m];
    }
    cout<<s;
    return 0;
}