#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[513][513];
int n;

void dfs(int n,int x,int y){
    if(n<1){
        return;
    }
    for(int i=x-n+1;i<=x;i++){
        for(int j=y-n+1;j<=y;j++){
            a[i][j]=0;
        }
    }
    dfs(n/2,x-n/2,y+n/2);
    dfs(n/2,x+n/2,y-n/2);
    dfs(n/2,x+n/2,y+n/2);
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=1<<n;i++){
        for(int j=1;j<=1<<n;j++){
            a[i][j]=1;
        }
    }
    dfs((1<<n)/2,(1<<n)/2,(1<<n)/2);
    for(int i=1;i<=1<<n;i++){
        for(int j=1;j<=1<<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}