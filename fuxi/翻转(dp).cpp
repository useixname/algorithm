#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int f[N][2];
char c[N][2];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i][0]>>c[i][1];
    }
    memset(f,0x3f3f3f3f,sizeof(f));
    f[1][0]=f[1][1]=2;
    for(int i=2;i<=n;i++){
        for(int t=0;t<2;t++){
            for(int p=0;p<2;p++){
                if(c[i][t]==c[i-1][(p+1)%2]){
                    f[i][t]=min(f[i][t],f[i-1][p]+1);
                }
                else{
                    f[i][t]=min(f[i][t],f[i-1][p]+2);
                }
            }
        }
    }
    cout<<min(f[n][0],f[n][1]);
    return 0;
}