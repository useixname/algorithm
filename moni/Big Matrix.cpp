#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10,mod=1e9+7;
int a[N][N],b[N][N];
int n,a1,b1,a2,b2,ans;


// 计算矩阵 C = AB 中所有元素的和
long long calculateMatrixSum(int n, int a1, int a2, int b1, int b2) {
    // 计算等差数列和所需的基本量
    long long sum_i = n * (n - 1) / 2;           // i 的和
    long long sum_i_squared = sum_i * (2 * n - 1) / 3;  // i^2 的和
    long long sum_j = sum_i;                      // j 的和，与 i 相同
    long long sum_j_squared = sum_i_squared;      // j^2 的和，与 i 相同

    // 使用推导公式计算结果
    long long sum_A = n * sum_i * a1 + n * sum_j * a2;
    long long sum_B = n * sum_i * b1 + n * sum_j * b2;

    long long sum_AB = n * (a1 * b1 * sum_i_squared + a1 * b2 * sum_i * sum_j +
                            a2 * b1 * sum_j * sum_i + a2 * b2 * sum_j_squared);

    return sum_AB;
}

signed main(){
    ios_base::sync_with_stdio(0);
    while(cin>>n>>a1>>a2>>b1>>b2){
        cout<<calculateMatrixSum(n,a1,a2,b1,b2)%mod<<'\n';
    }
    return 0;
}