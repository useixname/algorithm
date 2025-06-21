#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int pre[N];
int n;

void init(){
    for(int i=0;i<=N;i++){
        pre[i]=i;
    }
}

int find(int x){
    return pre[x]==x?x:(pre[x]=find(pre[x]));
}

// 2 1 1 3 4
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    init();
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        x=find(x);
        cout<<x<<" ";
        pre[x]=x+1;
    }
    return 0;
}