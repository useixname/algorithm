#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt[10];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        int x=i;
        while(x){
            int t=x%10;
            cnt[t]++;
            x/=10;
        }
    }
    for(int i=0;i<10;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}