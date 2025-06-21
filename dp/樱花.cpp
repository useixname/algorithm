#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int f[N],t[N],c[N],p[N];
int ts,te,n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>ts>>te>>n;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=c[i];j--){
            f[j]=max(f[j],f[j-t[i]]+c[i]);
        }
    }
}