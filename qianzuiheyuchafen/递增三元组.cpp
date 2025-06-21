#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N],c[N],suml[N],sumr[N];
int n,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(a+1,a+n+1);
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
        int pos1=lower_bound(a+1,a+n+1,b[i])-a-1;  //找出第一个小于b[i]的数的下标
        int pos2=upper_bound(c+1,c+n+1,b[i])-c;    //找出第一个大于b[i]的数的下标
        ans+=pos1*(n-pos2+1);
    }
    cout<<ans;
    return 0;
}