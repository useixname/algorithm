#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],cnt[N];
int n,maxn=-1,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int h=a[i];
        while(h>1){
            h=sqrtl(h/2+1);
            cnt[i]++;
        }
        maxn=max(maxn,cnt[i]);
    }
    for(int i=maxn;i>0;i--){
        for(int j=1;j<=n;j++){
            if(cnt[j]==i){
                if(a[j]!=a[j+1]){
                    ans++;
                }
                a[j]=sqrtl(a[j]/2+1);
                cnt[j]--;
            }
        }
    }
    cout<<ans;
    return 0;
}