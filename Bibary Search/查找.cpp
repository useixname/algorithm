#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        int x;
        cin>>x;
        int l=0,r=n+1;
        while(l+1<r){
            int mid=l+r>>1;
            if(a[mid]>=x) r=mid;
            else l=mid;
        }
        if(a[r]==x) printf("%d ",r);
        else printf("%d ",-1);
    }
    return 0;
}