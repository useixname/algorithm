#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int a[N][N];
int n,nx,ny,k;

void dfs(int x,int y,char ch){
    a[x][y]=++k;
    if(x==nx&&y==ny){
        cout<<a[x][y];
        return;
    }
    if(ch=='r'){
        if(y==n||a[x][y+1]) dfs(x+1,y,'d');
        else dfs(x,y+1,'r');
    }
    else if(ch=='d'){
        if(x==n||a[x+1][y]) dfs(x,y-1,'l');
        else dfs(x+1,y,'d');
    }
    else if(ch=='l'){
        if(y==1||a[x][y-1]) dfs(x-1,y,'u');
        else dfs(x,y-1,'l');
    }
    else{
        if(x==1||a[x-1][y]) dfs(x,y+1,'r');
        else dfs(x-1,y,'u');
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>nx>>ny;
    dfs(1,1,'r');
    return 0;
}