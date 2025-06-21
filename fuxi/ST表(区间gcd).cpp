#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int stgcd[N][16],a[N],log_2[N];
int n,m;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    return gcd(b,a%b);
}

void built(){
    log_2[0]=-1;
    for(int i=1;i<=n;i++){
        log_2[i]=log_2[i>>1]+1;
        stgcd[i][0]=a[i];
    }
    int power=log_2[n];
    for(int p=1;p<=power;p++){
        for(int i=1;i+(1<<p)-1<=n;i++){
            stgcd[i][p]=gcd(stgcd[i][p-1],stgcd[i+(1<<(p-1))][p-1]);
        }
    }
}

int query(int l,int r){
    int p=log_2[r-l+1];
    return gcd(stgcd[l][p],stgcd[r-(1<<p)+1][p]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    built();
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<'\n';
    }
    return 0;
}