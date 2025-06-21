#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int st[N][20],a[N],l[N],r[N],index1[N],log_2[N];
int n,m,cnt=1;

void built(){
    log_2[0]=-1;
    for(int i=1;i<=cnt;i++){
        log_2[i]=log_2[i>>1]+1;
        st[i][0]=r[i]-l[i]+1;
    }
    int power=log_2[cnt];
    for(int p=1;p<=power;p++){
        for(int i=1;i+(1<<p)-1<=cnt;i++){
            st[i][p]=max(st[i][p-1],st[i+(1<<(p-1))][p-1]);
        }
    }
}

int query(int a,int b){
    int l1=index1[a],r1=index1[b];
    if(l1==r1) return b-a+1;
    int d1=r[l1]-a+1,d2=b-l[r1]+1,c=0;
    if(l1+1<r1){
        int p=log_2[(r1-1)-(l1+1)+1];
        c=max(st[l1+1][p],st[l1+1+(1<<p)+1][p]);
    }
    return max(max(d1,d2),c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    cin>>a[1];
    l[cnt]=1;
    index1[1]=1;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1]){
            r[cnt]=i-1;
            l[++cnt]=i;
        }
        index1[i]=cnt;
    }
    r[cnt]=n;
    built();
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<query(a,b)<<'\n';
    }
    return 0;
}