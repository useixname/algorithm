#include<bits/stdc++.h>
using namespace std;
int a[100000][11];
int n,ans=0,now;

void dfs(int step){
    if(step>10||now>n) return;
    if(step==10&&now==n){
        ans++;
        for(int i=0;i<10;i++){
            a[ans][i]=a[ans-1][i];
        }
        return;
    }
    for(int i=1;i<=3;i++){
        now+=i;
        a[ans][step]=i;
        dfs(step+1);
        now-=i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    if(n>30) cout<<0;
    else{
        dfs(0);
        cout<<ans<<'\n';
        for(int i=0;i<ans;i++){
            for(int j=0;j<10;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}