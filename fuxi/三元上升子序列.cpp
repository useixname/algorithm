/*
树状数组,离散化,逆序对
int len=unique(b+1,b+n+1)-(b+1);
*/

/*
for(int i=1;i<=n;i++){
    int pos=lower_bound(b+1,b+len+1,a[i])-b;
    left[i]=sum(pos-1);
    add(pos,1);
}

for(int i=n;i>=1;i--){
    int pos=lower_bound(b+1,b+len+1,a[i])-b;
    right[i]=n-i-sum(pos);
    add(pos,1);
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],l[N],r[N],s1[N],s2[N];
int n,ans;

int low_bit(int x){
    return x&-x;
}

int sum(int x,int *s){
    int ret=0;
    while(x){
        ret+=s[x];
        x-=low_bit(x);
    }
    return ret;
}

void add(int x,int c,int *s){
    while(x<=n){
        s[x]+=c;
        x+=low_bit(x);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int len=unique(b+1,b+n+1)-(b+1);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(b+1,b+n+1,a[i])-b;
        l[i]=sum(pos-1,s1);
        add(pos,1,s1);
    }
    for(int i=n;i>=1;i--){
        int pos=lower_bound(b+1,b+n+1,a[i])-b;
        r[i]=n-i-sum(pos,s2);
        add(pos,1,s2);
    }
    for(int i=1;i<=n;i++){
        ans+=l[i]*r[i];
    }
    cout<<ans;
    return 0;
}