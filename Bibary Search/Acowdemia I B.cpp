#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,l;
int a[N];

bool chk(int x){
    if(x>n) return false;
    int cnt=0,s=l;
    int ops=lower_bound(a+1,a+1+n,x)-a;
    cnt+=(n-ops+1);
    for(int i=ops-1;i>=1;i--){
        if(x-a[i]==1){
            s--;
            if(s<0) break;
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt>=x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=0,r=N;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}