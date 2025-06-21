#include<bits/stdc++.h>
using namespace std;
int n,ans;

int front(int x){
    int ret=0;
    while(x){
        ret+=x%10;
        x/=10;
    }
    return ret;
}

int main(){
    cin>>n;
    while(n!=0){
        n-=front(n);
        ans++;
    }
    cout<<ans;
}