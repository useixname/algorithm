#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    int l=0,r=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!l&&a[i]){
            l=i;
        }
        if(a[i]){
            r=i;
        }
    }
    if(l==r&&l==0){
        cout<<0;
    }
    else{
        cout<<r-l+1;
    }
    return 0;
}