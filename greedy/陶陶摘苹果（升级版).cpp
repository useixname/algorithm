#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,s,h,b,ans;

struct node{
    int hi,si;
    bool operator<(const node & pa) const{
        if(si==pa.si){
            return hi<pa.hi;
        }
        return si<pa.si;
    }
}a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s>>h>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i].hi>>a[i].si;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(s-a[i].si>=0&&a[i].hi<=h+b){
            s-=a[i].si;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}