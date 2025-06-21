#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,ans[N][2];

struct node{
    int h,l,r,t;
    bool operator<(const node & pa) const{
        if(h==pa.h){
            return t>pa.t;
        }
        return h<pa.h;
    }
}a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].h>>a[i].l>>a[i].r;
        a[i].t=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int flagl=1,flagr=1;
        for(int j=i-1;j>=1;j--){
            if(flagl&&a[j].l<a[i].l&&a[i].l<a[j].r&&a[j].h<a[i].h){
                flagl=0;
                ans[a[i].t][0]=a[j].t;
            }
            if(flagr&&a[j].l<a[i].r&&a[i].r<a[j].r&&a[j].h<a[i].h){
                flagr=0;
                ans[a[i].t][1]=a[j].t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<'\n';
    }
    return 0;
}