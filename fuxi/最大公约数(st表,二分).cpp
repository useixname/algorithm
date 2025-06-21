#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int stgcd[N][16],a[N],log_2[N];
int n,cnt;

int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

void build(){
    log_2[0]=-1;
    for(int i=1;i<=n;i++){
        log_2[i]=log_2[i>>1]+1;
        stgcd[i][0]=a[i];
    }
    int lower=log_2[n];
    for(int p=1;p<=lower;p++){
        for(int i=1;i+(1<<p)-1<=n;i++){
            stgcd[i][p]=gcd(stgcd[i][p-1],stgcd[i+(1<<(p-1))][p-1]);
        }
    }
}

int query(int l,int r){
    int p=log_2[r-l+1];
    return gcd(stgcd[l][p],stgcd[r-(1<<(p))+1][p]);
}

bool chk(int len){
    for(int i=1;i+len-1<=n;i++){
        if(query(i,i+len-1)==1) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) cnt++;
    }
    if(cnt){
        cout<<n-cnt;
        return 0;
    }
    build();
    int l=1,r=n+1;
    while(l+1<r){
        int mid=(l+r>>1);
        if(chk(mid)) r=mid;
        else l=mid;
    }
    if(r==n+1) cout<<-1;
    else cout<<(r-1)+(n-1);
    return 0;
}