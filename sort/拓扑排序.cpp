#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int din[N];
vector<int>e[N],tp;

bool tpsort(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!din[i]) q.push(i);
    }
    while(q.size()){
        int x=q.front();
        q.pop();
        tp.push_back(x);
        for(auto y:e[x]){
            if(--din[y]==0) q.push(y);
        }
    }
    return tp.size()==n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        din[v]++;
    }
    tpsort();
    return 0;
}