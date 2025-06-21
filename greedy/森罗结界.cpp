#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin>>n;
    int cnt1=n/5,cnt2=n%5;
    if(cnt2>=3){
        cout<<2;
        cnt1--;
    }
    for(int i=1;i<=cnt1;i++){
        cout<<1;
    }
    return 0;
}