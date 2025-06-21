#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int f[N],s[N];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    memset(f,0x3f3f3f3f,sizeof(f));
    f[0]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==1) s[i]=s[i-1]+1;
        else s[i]=s[i-1]-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(abs(s[i]-s[j-1])<=m||abs(s[i]-s[j-1])==i-j+1){
                f[i]=min(f[j-1]+1,f[i]);
            }
        }
    }
    cout<<f[n];
    return 0;
}