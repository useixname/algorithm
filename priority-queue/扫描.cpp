#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],q[N];
int n,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        while(h<=t&&a[i]>=a[q[t]]) t--;
        q[++t]=i;
        if(q[h]<i-k+1) h++;
        if(i>=k) cout<<a[q[h]]<<'\n';
    }
    return 0;
}