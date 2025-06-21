#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int a[N];
int n, k, m; // 这里 m 表示给定的方差阈值 T
 
// 检查：前 mid 个成绩中是否存在一个长度为 k 的连续子序列，其方差小于 m
bool chk(int mid) {
    // 如果 mid 小于 k，则不可能选出 k 个成绩
    if(mid < k) return false;
    
    int b[N];
    int sum[N] = {0}, sum_2[N] = {0};
    // 将 a[1..mid] 复制到 b[1..mid]
    memcpy(b+1, a+1, sizeof(int)*mid);
    // 对 b[1..mid] 进行排序
    sort(b+1, b+mid+1);
    
    // 计算前缀和及前缀平方和，注意数组下标从 1 开始
    for(int i = 1; i <= mid; i++){
        sum[i] = sum[i-1] + b[i];
        sum_2[i] = sum_2[i-1] + b[i] * b[i];
    }
    
    // 枚举所有连续长度为 k 的子数组
    // 对于区间 [i-k+1, i]，区间和 S = sum[i] - sum[i-k]，平方和 SS = sum_2[i] - sum_2[i-k]
    // 方差 = SS/k - (S/k)^2 = (SS*k - S^2) / (k^2)
    for(int i = k; i <= mid; i++){
        double S = sum[i] - sum[i - k];
        double SS = sum_2[i] - sum_2[i - k];
        double variance = (SS * k - S * S) / (double)(k * k);
        if(variance < m) return true;
    }
    return false;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 0, r = n; // 答案至少在 [k, n] 范围内，故 l 从 0 开始（保证 mid < k 返回 false）
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(chk(mid)) r = mid;
        else l = mid;
    }
    if(l==n-1){
      cout<<-1;
      return 0;
    }
    cout << r;
    return 0;
}
