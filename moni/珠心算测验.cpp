#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],b[20010];
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int k=a[i]+a[j];
            if(b[k]){
                ans++;
                b[k]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}