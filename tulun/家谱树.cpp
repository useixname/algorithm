#include<bits/stdc++.h>
using namespace std;
const int N=110;
int din[N];
vector<int>e[N],tp;
int n;

void tp_sort(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(!din[i]) q.push(i);
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        tp.push_back(t);
        for(auto x:e[t]){
            if(--din[x]==0) q.push(x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        while(x){
            din[x]++;
            e[i].push_back(x);
            cin>>x;
        }
    }
    tp_sort();
    for(auto x:tp){
        cout<<x<<" ";
    }
    return 0;
}