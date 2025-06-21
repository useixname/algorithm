#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e2+10;
int a[N];
int n,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int st=0,et=n;
    bool flag=true;
    for(int i=1;i<=n;i++){
        ans+=pow(a[st]-a[et],2);
        if(flag){
            st++;
        }
        else{
            et--;
        }
        flag=!flag;
    }
    cout<<ans;
    return 0;
}