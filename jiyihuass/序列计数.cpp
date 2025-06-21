#include<bits/stdc++.h>
using namespace std;
const int mod=1e4;
const int N=1e3+10;
int f[N][N];
int n;

// 小明想知道，满足以下条件的正整数序列的数量：
// 第一项为 n，第二项不超过n；从第三项开始，每一项小于前两项的差的绝对值。
// 请计算，对于给定的n，有多少种满足条件的序列。

// dfs(x,y)表示以x开头且第二个数小于y的序列的个数
int dfs(int x,int y){
    if(f[x][y]) return f[x][y];
    if(y<=0) return 0;
    // 有两种选择：1.序列后面不接任何的数字 dfs(x,y)=dfs(x,y-1)+1; dfs(5,4)=dfs(5,3)+1;
    // 这里加一是因为序列后面不接任何的数字实际上就是加了一个新方案数，所以要加一。
    // dfs(5,4)与dfs(5,3)是两个不同的序列。而dfs(5,4)与dfs(4,z)是相同的序列。
    // 2.序列后面接数字,dfs(x,y)=dfs(x,abs(x-y)-1);
    f[x][y]=(dfs(x,y-1)+1+dfs(y,abs(x-y)-1))%mod;
    return f[x][y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    cout<<dfs(n,n);
    return 0;
}