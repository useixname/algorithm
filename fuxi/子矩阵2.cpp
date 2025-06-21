#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int g[N][N],q[N],f_max[N][N],f_min[N][N];
int n,m,k,ans;

void get_max(int *g,int *f_max,int n,int k){
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        while(h<=t&&g[i]>=g[q[t]]){
            t--;
        }
        q[++t]=i;
        if(i-q[h]+1>k) h++;
        f_max[i]=g[q[h]];
    }
}

void get_min(int *g,int *f_min,int n,int k){
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        while(h<=t&&g[i]<=g[q[t]]){
            t--;
        }
        q[++t]=i;
        if(i-q[h]+1>k) h++;
        f_min[i]=g[q[h]];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        get_max(g[i],f_max[i],m,k);
        get_min(g[i],f_min[i],m,k);
    }
    int a[N],b[N],c[N];
    for(int i=k;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[j]=f_max[j][i];
        }
        get_max(a,c,n,k);
        for(int j=1;j<=n;j++){
            a[j]=f_min[j][i];
        }
        get_min(a,c,n,k);
        for(int j=k;j<=n;j++){
            ans+=b[j]*c[j];
        }
    }
    cout<<ans;
    return 0;
}