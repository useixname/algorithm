<<<<<<< HEAD
<<<<<<< HEAD
// #include<cstdio>
// #include<algorithm>
// #define size 1000010
// using namespace std;
// #define int long long
// const int N=4e5+10;
// int a[N],dp[N][N];
// int n;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         a[i+n]=a[i];
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=i+n-1;j<=2*n-1;j++){
//             for(int k=i;k<j;k++){
//                 dp[i][j]=max(dp[i][k]+dp[k+1][j],dp[i][j]);
//             }
//         }
//     }
// }

#include<bits/stdc++.h>
using namespace std;

int ans=0x7f3f3f7f;
int dp[2010][2010];
int a[2010][2010];
int n,m;


void dfs(int u,int v,int sum){
    if(u==0){
        ans=min(ans,sum);
        return;
    }
    if(v==1){
        dfs(u-1,m,sum+a[v][u]);
        dfs(u-1,v,sum+a[v][u]);
    }
    else{
        dfs(u-1,v-1,sum+a[v][u]);
        dfs(u-1,v,sum+a[v][u]);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(j!=1){
    //             dp[i][j]=min(dp[i-1][j-1]+a[j][i],dp[i-1][j]+a[j][i]);
    //         }
    //         else{
    //             dp[i][j]=min(dp[i-1][m]+a[j][i],dp[i-1][j]+a[j][i]);
    //         }
    //     }
    // }
    // for(int i=1;i<=m;i++){
    //     ans=min(ans,dp[n][i]);
    // }
    for(int i=1;i<=m;i++){
        dfs(n,i,0);
    }
    cout<<ans;
    return 0;
}

=======
=======
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
int a[N],dp[N][N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+n-1;j<=2*n-1;j++){
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][k]+dp[k+1][j],dp[i][j]);
            }
        }
    }
<<<<<<< HEAD
}
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
=======
}
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
