#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[15];
int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>a[1];
    if(a[1]!=1){
        cout<<a[1];
        return 0;
    }
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i-1]+1!=a[i]){
            cout<<a[i];
            return 0;
        }
    }
    cout<<-1;
    return 0;
}