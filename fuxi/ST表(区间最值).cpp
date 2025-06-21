#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int stmax[N][16],stmin[N][16],log_2[N],a[N];
int n,m;

void bulit(){
    log_2[0]=-1;
    for(int i=1;i<=n;i++){
        log_2[i]=log_2[i>>1]+1;
        stmax[i][0]=a[i];
        stmin[i][0]=a[i];
    }
    int lower=log_2[n];
    for(int p=1;p<=lower;p++){
        for(int i=1;i+(1<<p)-1<=n;i++){
            stmax[i][p]=max(stmax[i][p-1],stmax[i+(1<<(p-1))][p-1]);
            stmin[i][p]=min(stmin[i][p-1],stmin[i+(1<<(p-1))][p-1]);
        }
    }
}

int query(int l,int r){
    int p=log_2[r-l+1];
    int a=max(stmax[l][p],stmax[r-(1<<p)+1][p]);
    int b=min(stmin[l][p],stmin[r-(1<<p)+1][p]);
    return a-b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bulit();
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<'\n';
    }
    return 0;
}