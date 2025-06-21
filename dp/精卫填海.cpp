#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int f[N],w[N],v[N];
int m,n,c;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>m>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j>=v[i];j--){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    for(int i=1;i<=c;i++){
        if(f[i]>=m){
            cout<<c-i;
            return 0;
        }
    }
    cout<<"Impossible";
    return 0;
}