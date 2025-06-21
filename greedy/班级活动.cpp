#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],num[N];
int n,cnt_1,cnt_2,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[a[i]]++;
    }
    for(int i=0;i<N;i++){
        if(num[i]==1) cnt_1++;
        else if(num[i]>=2) cnt_2+=(num[i]-2);
    }
    if(cnt_1<cnt_2) ans=cnt_2;
    else ans=(cnt_1-cnt_2)/2+cnt_2;
    cout<<ans;
    return 0;
}