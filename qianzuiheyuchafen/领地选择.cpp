#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N][N],sum[N][N];
int n,m,c,ans=INT_MIN,x,y;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for(int x1=1;x1+c-1<=n;x1++){
        for(int y1=1;y1+c-1<=m;y1++){
            int x2=x1+c-1,y2=y1+c-1;
            int s=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
            if(s>ans){
                ans=s;
                x=x1;
                y=y1;
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}