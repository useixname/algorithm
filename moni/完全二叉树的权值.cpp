#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int n,cnt=1,ans,maxn=-0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int cnt=1;;cnt++){
        int s=0;
        for(int i=pow(2,cnt-1);i<=pow(2,cnt)-1;i++){
            s+=a[i];
        }
        if(s>maxn){
            maxn=s;
            ans=cnt;
        }
        if(pow(2,cnt)-1>n){
            break;
        }
    }
    cout<<ans;
    return 0;
}