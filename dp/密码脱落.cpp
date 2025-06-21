#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int f[N][N];
char s[N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1;
    n=strlen(s+1);
    // f[i][j]=f[i+1][j-1]+2
    for(int i=n;i>=1;i--){
        f[i][i]=1;
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j]){
                f[i][j]=f[i+1][j-1]+2;
            }
            else{
                f[i][j]=max(f[i+1][j],f[i][j-1]);
            }
        }
    }
    cout<<n-f[1][n];
    return 0;
}