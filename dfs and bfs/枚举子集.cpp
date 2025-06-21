#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n;
char ret[N];

void dfs(int step){
    if(step==n+1){
        for(int i=1;i<=n;i++){
            cout<<ret[i];
        }
        cout<<'\n';
        return;
    }
    ret[step]='N';
    dfs(step+1);
    ret[step]='Y';
    dfs(step+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    dfs(1);
    return 0;
}