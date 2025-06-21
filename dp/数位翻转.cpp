#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf INT_MIN
const int N=1e5+10;
int a[N],d[N],f[N],maxn[N];
int n,m,s,sd;

int fun(int x){
    if(x==0) return 0;
    int ret=0;
    vector<int>t;
    while(x){
        t.push_back(x&1);
        x>>=1;
    }
    for(int x:t){
        ret=(ret<<1)|x;
    }
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        d[i]=fun(a[i])-a[i];
        // cout<<d[i]<<" ";
    }
    for(int i=1;i<=m;i++){
        f[i-1]=inf;
        for(int j=i;j<=n-(m-i);j++){
            f[j]=max(f[j-1],maxn[j-1])+d[j];
        }
        maxn[i-1]=inf;
        for(int j=i;j<=n-(m-i);j++){
            maxn[j]=max(maxn[j-1],f[j]);
        }
        sd=max(sd,*max_element(f+i,f+n+1));
    }
    // cout<<s<<" "<<sd<<'\n';
    cout<<s+sd;
    return 0;
}