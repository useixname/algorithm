#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int f[N][N];
string s1,s2;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    if(n*m==0){
        return n+m;
    }
    for(int i=1;i<=n;i++){
        f[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        f[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a=f[i][j-1]+1;
            int b=f[i-1][j]+1;
            int c=f[i-1][j-1];
            if(s1[i-1]!=s2[j-1]){
                c+=1;
            }
            f[i][j]=min(c,min(a,b));
        }
    }
    cout<<f[n][m];
    return 0;
}