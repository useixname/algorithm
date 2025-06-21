#include<bits/stdc++.h>
using namespace std;
#define int long long
bitset<10010>b[55],c1,c2;
int n,m;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        b[i].reset();
        int l;
        cin>>l;
        for(int j=1;j<=l;j++){
            int x;
            cin>>x;
            b[i][x]=1;
        }
    }
    cin>>m;
    while(m--){
        c1.reset();c2.reset();
        int x,y;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            if(b[i][x]) c1|=b[i];
            if(b[i][y]) c2|=b[i];
        }
        c1[x]=0;
        c2[y]=0;
        auto t=c1&c2;
        int ans=t.count();
        cout<<ans<<'\n';
    }
    return 0;
}