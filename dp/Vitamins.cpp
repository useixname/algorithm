#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int f[N],w[N];
int n,cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int vis[3];
        cin>>w[i];
        string s;
        cin>>s;
        int l=s.size();
        for(int i=0;i<l;i++){
            int t=s[i]-'a';
            if(!vis[t]){
                cnt++;
                vis[t]=1;
            }
        }
    }
    if(cnt<3){
        cout<<-1;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            
        }
    }
}