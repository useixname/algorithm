#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[55][55];

bool chk(int x,int k){
    memset(a,0,sizeof(a));
    bitset<32>bs=x;
    for(int i=0;i<k;i++){
        a[k][k-i]=bs[i];
    }
    int cnt_b=bs.count();
    int cnt_a=k-bs.count();
    for(int i=k-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(a[i+1][j]==a[i+1][j+1]) a[i][j]=0,cnt_a++;
            else a[i][j]=1,cnt_b++;
        }
        if(cnt_a>n||cnt_b>m) return false;
    }
    return cnt_a==n&&cnt_b==m;
}

int main(){
    cin>>n>>m;
    int k=sqrt(2*(n+m));
    for(int i=0;i<(1<<k);i++){
        if(chk(i,k)) ans++;
    }
    cout<<ans;
    return 0;
}