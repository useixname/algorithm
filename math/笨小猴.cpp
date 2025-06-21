#include<bits/stdc++.h>
using namespace std;

int maxn=0,minn=110,cnt;
string s;
int a[27],vis[110],prim[110];

void get_prim(){
    for(int i=2;i<=110;i++){
        if(!vis[i]){
            prim[++cnt]=i;
        }
        for(int j=1;i*prim[j]<=110;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

int main(){
    memset(a,0,sizeof(a));
    get_prim();
    cin>>s;
    int n=s.size();
    vis[1]=vis[0]=1;
    for(int i=0;i<n;i++){
        int x=s[i]-'a'+1;
        a[x]++;
    }
    for(int i=1;i<=26;i++){
        if(a[i]){
            maxn=max(a[i],maxn);
            minn=min(a[i],minn);
        }
    }
    int k=maxn-minn;
    if(!vis[k]) cout<<"Lucky Word"<<'\n'<<k;
    else cout<<"No Answer"<<'\n'<<0;
    return 0;
}