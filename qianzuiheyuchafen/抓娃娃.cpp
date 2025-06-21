#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int d[N],sum[N];
struct node{
    int l,r,mid;
}a[N],b[N];
int n,m;

void insert(int l,int r,int c){
    d[l]+=c;
    d[r+1]-=c;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        insert(a[i].l,a[i].r,1);
        int d=a[i].l+a[i].r;
        int mid=d>>1;
        if(d&1) mid++;
        a[i].mid=mid;
    }
    for(int i=1;i<=m;i++){
        cin>>b[i].l>>b[i].r;
        insert(b[i].l,b[i].r,-1);
    }
    
}