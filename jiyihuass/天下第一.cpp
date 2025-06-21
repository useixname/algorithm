#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
short book[N][N];
int t,mod;

int dfs(int x,int y){
    if(book[x][y]==-1) return -1;
    if(book[x][y]) return book[x][y];
    book[x][y]=-1;
    if(!x) return book[x][y]=1;
    if(!y) return book[x][y]=2;
    int num=(x+y)%mod;
    return book[x][y]=dfs(num,(num+y)%mod);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t>>mod;
    while(t--){
        int x,y;
        cin>>x>>y;
        int ans=dfs(x,y);
        if(ans==-1) cout<<"error"<<'\n';
        else cout<<ans<<'\n';
    }
    return 0;
}