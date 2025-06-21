#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int fa[N];

void init(){
    for(int i=1;i<=n+1;i++){
        fa[i]=i;
    }
}

int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    init();
    while(m--){
        int l,r;
        cin>>l>>r;
        int f=find(l);
        while(f<=r){
            fa[find(f)]=find(f+1);
            f=find(f);
            n--;
        }
        cout<<n<<'\n';
    }
    return 0;
}