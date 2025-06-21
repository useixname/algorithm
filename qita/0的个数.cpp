#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int vis[N],prim[N],book[N],is_d[N],d[N];
int a,b,cnt;

void get_prim(){
    for(int i=2;i<=N;i++){
        if(!vis[i]){
            prim[++cnt]=i;
        }
        for(int j=1;i*prim[j]<=N;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

int judge(int x){
    int k=x;
    memset(book,0,sizeof(book));
    int cnt=0,t=0;
    while(t!=1){
        t=0;
        while(x){
            int a=x%10;
            x/=10;
            t+=a*a;
        }
        x=t;
        if(!book[x]) book[x]=1;
        else break;
        cnt++;
    }
    if(t!=1) return 0;
    else{
        int n=k,t1=0;
        while(t1!=1){
            t1=0;
            while(n){
                int a=n%10;
                n/=10;
                t1+=a*a;
            }
            n=t1;
            if(n<=b) is_d[n]=1;
        }
    }
    if(!vis[k]) return 2*cnt;
    else return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    get_prim();
    cin>>a>>b;
    int flag=0;
    for(int i=a;i<=b;i++){
        d[i]=judge(i);
    }
    for(int i=a;i<=b;i++){
        if(d[i]&&!is_d[i]) flag=1,cout<<i<<" "<<d[i]<<'\n';
    }
    if(!flag) cout<<"SAD";
    return 0;
}