#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e15+10;
unordered_map<int,bool>m;
int vis[N],prim[N],cnt;
int a,b;
void get_prim(){
    for(int i=2;i<=N;i++){
        if(!vis[i]) m[i]=true,prim[++cnt]=i;
        for(int j=1;i*prim[j]<=N;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    get_prim();
    cin>>a>>b;
    if(m[abs(a-b)]){
        cout<<2<<'\n';
        cout<<a<<" "<<b;
        return 0;
    }
}