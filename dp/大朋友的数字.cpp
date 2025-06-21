#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int f[N],l[N],a[N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[1]=a[1];
    for(int i=1;i<=n;i++){
        l[i]=1;
        f[i]=a[i];
        for(int j=1;j<i;j++){
            if(a[i]>=a[j]){
                if(l[j]+1>l[i]){ 
                    l[i]=l[j]+1;
                    f[i]=f[j]+a[i];
                }
                else if(l[j]+1==l[i]){
                    f[i]=max(f[i],f[j]+a[i]);
                }
            }
        }
        cout<<f[i]<<" ";
    }
    return 0;
}