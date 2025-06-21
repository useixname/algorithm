#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N],c[N],t[N],d[N];
int n,ans;


int lowbit(int x){
    return x&-x;
}

void add(int x,int k){
    while(x<=N){
        t[x]+=k;
        x+=lowbit(x);
    }
}

int sum(int x){
    int ret=0;
    while(x){
        ret+=t[x];
        x-=lowbit(x);
    }
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]++;
    }
    for(int i=1;i<=n;i++){
        c[i]+=sum(N-1)-sum(a[i]);
        add(a[i],1);
    }
    memset(t,0,sizeof(t));
    for(int i=n;i>=1;i--){
        c[i]+=sum(a[i]-1);
        add(a[i],1);
    }
    for(int i=1;i<=n;i++){
        ans+=((1+c[i])*c[i])/2;
    }
    cout<<ans;
    return 0;
}