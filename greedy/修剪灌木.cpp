#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=max(2*(i-1),2*(n-i));
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<'\n';
    }
    return 0;
}
// 2 1 1 1