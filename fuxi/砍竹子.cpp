#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
set<int>st;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        set<int>cur;
        while(x!=1){
            cur.insert(x);
            if(!st.count(x)){
                ans++;
            }
            x=sqrtl(x/2+1);
        }
        st=cur;
    }
    cout<<ans;
    return 0;
}