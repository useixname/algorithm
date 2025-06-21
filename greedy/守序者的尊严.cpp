#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int n,t=1;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int k=2;
    while(k<=n){
        if(a[k]!=a[k-1]){
            t++;
        }
        k++;
    }
    cout<<t;
    return 0;
}