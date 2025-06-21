#include<bits/stdc++.h>
using namespace std;
int ans;
void dfs(int step,int sum){
    if(step==30){
        if(sum==70){
            ans++;
        }
        return;
    }
    if(sum==70){
        ans++;
        return;
    }
    dfs(step+1,sum+10);
    dfs(step+1,0);
}

int main(){
    dfs(0,0);
    cout<<ans;
    return 0;
}