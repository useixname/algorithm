#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int vis[N];
int n,m,ans;
deque<int>q;

int main(){
    ios_base::sync_with_stdio(0);
    int n,m,ans;
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(!vis[x]){
            vis[x]=1;
            ans++;
            if(q.size()<m) q.push_front(x);
            else vis[q.back()]=0,q.pop_back(),q.push_front(x);
        }
    }
    cout<<ans;
    return 0;
}