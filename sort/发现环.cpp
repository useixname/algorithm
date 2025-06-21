#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
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
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        din[v]++;
        din[u]++;
    }
    tpsort();
    for(int i=1;i<=n;i++){
        if(din[i]!=1) cout<<i<<" ";
    }
    return 0;
}