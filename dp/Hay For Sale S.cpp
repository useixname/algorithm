#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int n,m;
int w[5010],f[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+w[i]);
        }
    }
    cout<<f[m];
    return 0;
}