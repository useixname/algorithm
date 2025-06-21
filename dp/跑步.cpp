#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10;
int n;
int f[N];
// 如果我们将要跑的距离n看做背包容积，每次跑的距离i看做物品代价，物品代价:1 2 3 4 ... n
// 就可以发现这其实是个 01背包求方案数的题目。
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            f[j]+=f[j-i];
        }
    }
    cout<<f[n]-1;
    return 0;
}