#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int n,d,ans;
//1 2 3 4 5 6 7 8
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n-1;i++){
        if(a[i+1]-a[i-1]<=d){
            a[i]=a[i-1];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}