#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int g[N][N],f_max[N][N],f_min[N][N],q[N];
int n,m,k,ans=INT_MAX;

void get_rmax(int *a,int *b,int n,int k){
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        while(h<=t&&a[i]>=a[q[t]]){
            t--;
        }
        q[++t]=i;
        if(i-q[h]+1>k){
            h++;
        }
        b[i]=a[q[h]];
    }
}

void get_rmin(int *a,int *b,int n,int k){
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        while(h<=t&&a[i]<=a[q[t]]){
            t--;
        }
        q[++t]=i;
        if(i-q[h]+1>k){
            h++;
        }
        b[i]=a[q[h]];
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
        get_rmax(g[i],f_max[i],m,k);
        get_rmin(g[i],f_min[i],m,k);
    }
    int a[N],b[N],c[N];
    for(int i=k;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[j]=f_max[j][i];
        }
        get_rmax(a,b,n,k);
        for(int j=1;j<=n;j++){
            a[j]=f_min[j][i];
        }
        get_rmin(a,c,n,k);
        for(int j=k;j<=n;j++){
            ans=min(b[j]-c[j],ans);
        }
    }
    cout<<ans;
    return 0;
}