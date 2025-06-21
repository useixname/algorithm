#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n;
int f[N],sum[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum[i]=sum[i-1]+x;
    }
    if(sum[n]<0){
        cout<<"Impossible";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(sum[i]>=0){
            for(int j=0;j<i;j++){
                if(sum[i]-sum[j]>=0){
                    f[i]=max(f[j]+1,f[i]);
                }
            }
        }
    }
    cout<<f[n];
    return 0;
}