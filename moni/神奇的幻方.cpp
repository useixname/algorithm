#include<bits/stdc++.h>
using namespace std;
const int N=40;
struct node{
    int r,c;
}a[N*N];
int b[N][N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    memset(b,0,sizeof(b));
    cin>>n;
    a[1].r=1;a[1].c=n/2+1;
    b[a[1].r][a[1].c]=1;
    for(int k=2;k<=n*n;k++){
        if(a[k-1].r==1&&a[k-1].c!=n){
            a[k].r=n;
            a[k].c=a[k-1].c+1;
        }
        else if(a[k-1].c==n&&a[k-1].r!=1){
            a[k].c=1;
            a[k].r=a[k-1].r-1;
        }
        else if(a[k-1].r==1&&a[k-1].c==n){
            a[k].r=a[k-1].r+1;
            a[k].c=a[k-1].c;
        }
        else if(a[k-1].r!=1&&a[k-1].r!=1){
            if(!b[a[k-1].r-1][a[k-1].c+1]){
                a[k].r=a[k-1].r-1;
                a[k].c=a[k-1].c+1;
            }
            else{
                a[k].r=a[k-1].r+1;
                a[k].c=a[k-1].c;
            }
        }
        b[a[k].r][a[k].c]=k;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}