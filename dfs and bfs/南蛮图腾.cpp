#include<bits/stdc++.h>
using namespace std;
char a[1100][2100];
int n;

void dfs(int n,int x,int y){
    if(n==1){
        a[x][y]='/';
        a[x][y+1]='\\';
        a[x+1][y-1]='/';
        a[x+1][y]='_';
        a[x+1][y+1]='_';
        a[x+1][y+2]='\\';
    }
    else{
        dfs(n-1,x,y);
        dfs(n-1,x+(1<<n-1),y-(1<<n-1));
        dfs(n-1,x+(1<<n-1),y+(1<<n-1));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    memset(a,' ',sizeof(a));
    cin>>n;
    dfs(n,1,(1<<n));
    for(int i=1;i<=1<<n;i++){
        for(int j=1;j<=1<<n+1;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
    return 0;
}