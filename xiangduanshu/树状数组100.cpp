#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int n;

int lowbit(int x){
    return x&-x;
}

void add(int x,int k){
    while(x<=n){
        a[x]+=k;
        x+=lowbit(x);
    }
}

int sum(int x){
    int ret=0;
    while(x){
        ret+=a[x];
        x-=lowbit(x);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    add(5,10);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}