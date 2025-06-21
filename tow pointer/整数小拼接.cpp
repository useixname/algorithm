#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
int n, k, ans;

// 计算拼接后的数是否小于等于k
bool cal(int a, int b) {
    // 计算b的位数
    int numDigits = log10(b) + 1;
    long long t = a * pow(10, numDigits) + b;
    return t <= k;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;

    // 输入数组
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 升序排序
    sort(a + 1, a + n + 1);

    // 双指针法遍历
    int l = 1, r = n;
    while (l < r) {
        if (cal(a[l], a[r])) {
            ans += r - l;  // 满足条件，统计符合的对数
            l++;
        } else {
            r--;  // 不符合条件，减少右指针
        }
    }

    //必须保证数组是升序排列的,因为只有这样双指针（r指针能提前停止）才有意义。
    l = 1;r = n;
    while (l < r) {
        if (cal(a[r], a[l])) { //反着来一遍
            ans += r - l;  // 满足条件，统计符合的对数
            l++;
        } else {
            r--;  // 不符合条件，减少右指针
        }
    }

    // 输出结果
    cout << ans;
    return 0;
}
