#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int f[N];
int coin[4]={0,1,5,11};

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int minn=N;
        for(int j=1;j<=3;j++){
            if(i>=coin[j]) minn=min(minn,f[i-coin[j]]);
        }
        f[i]=minn+1;
    }
    cout<<f[n];
    return 0;
}