#include<bits/stdc++.h>
using namespace std;
const int N=3e4+10;
int n;
int a[N],f[N][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[1][2-a[1]]=1;
    f[1][a[1]-1]=0;
    for(int i=2;i<=n;i++){
        if(a[i]==1){
            f[i][0]=f[i-1][0];
            f[i][1]=min(f[i-1][1],f[i-1][0])+1;
        }
        else{
            f[i][0]=f[i-1][0]+1;
            f[i][1]=min(f[i-1][1],f[i-1][0]);
        }
    }
    cout<<min(f[n][0],f[n][1]);
    return 0;
}