#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s[N];
int n,ans;
struct node{
    int val,pos;
    bool operator<(const node & pa) const{
        if(val==pa.val) return pos>pa.pos;
        return val>pa.val;
    }
}a[N];

int low_bit(int x){
    return x&-x;
}

int sum(int x){
    int ret=0;
    while(x){
        ret+=s[x];
        x-=low_bit(x);
    }
    return ret;
}

void add(int x,int c){
    while(x<=n){
        s[x]+=c;
        x+=low_bit(x);
    }
}

bool cmp(int x,int y){
    return x>y;
}
//1 2 3 4 5
//5 4 3 2 1
//5 4 3 2 1
//5 3
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].pos=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ans+=sum(a[i].pos-1);
        add(a[i].pos,1);
    }
    cout<<ans;
    return 0;
}