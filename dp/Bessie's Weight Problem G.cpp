#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int m,n;
int a[550],f[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i];j--){
            f[j]=max(f[j],f[j-a[i]]+a[i]);
        }
    }
    cout<<f[m];
    return 0;
}