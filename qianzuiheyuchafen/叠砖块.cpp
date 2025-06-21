#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],diff[N];
int n,k;

void insert(int l,int r){
    diff[l]+=1;
    diff[r+1]-=1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    while(k--){
        int a,b;
        cin>>a>>b;
        insert(a,b);
    }
    for(int i=1;i<=n;i++){
        diff[i]+=diff[i-1];
    }
    sort(diff+1,diff+n+1);
    cout<<diff[n/2+1];
    return 0;
}