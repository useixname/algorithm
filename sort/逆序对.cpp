#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N],b[N];
long long ans=0;
void msort(int l,int r){
    if(l==r) return;
    int m=l+r>>1;
<<<<<<< HEAD
<<<<<<< HEAD
    msort(l,m);msort(m+1,r);//虏冒路脰

    int i=l,j=m+1,k=l;//潞脧虏垄
=======
    msort(l,m);msort(m+1,r);//拆分

    int i=l,j=m+1,k=l;//合并
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
=======
    msort(l,m);msort(m+1,r);//拆分

    int i=l,j=m+1,k=l;//合并
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
    while(i<=m&&j<=r){
        if(a[i]<=a[j]) b[k++]=a[i++];
        else b[k++]=a[j++],ans+=m-i+1;
    }
    while(i<=m){
        b[k++]=a[i++];
    }
    while(j<=r){
        b[k++]=a[j++];
    }
    for(int i=l;i<=r;i++){
        a[i]=b[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    msort(1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n'<<ans;
    return 0;
}