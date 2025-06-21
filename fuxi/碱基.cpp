#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INIT_MAX = 100000;  // 只要保证 “任意单个子串的出现次数最多不超过这个值” 即可
const int MAXK = 15;          // 假定 m 最大不会超过 15

// f[i][j] = C(i, j) （0 <= i <= INIT_MAX，0 <= j <= MAXK）
ll f[INIT_MAX+1][MAXK+1];

void init_combinations() {
    // Pascal 三角预处理
    // 只要 j <= i 且 j <= MAXK，我们才计算；其余 f[i][j] 默认为 0
    for (int i = 0; i <= INIT_MAX; i++) {
        for (int j = 0; j <= MAXK; j++) {
            if (j == 0) {
                f[i][j] = 1;  // C(i, 0) = 1
            } else if (j > i) {
                f[i][j] = 0;  // C(i, j)=0, 因为 j>i
            } else if (j == i) {
                f[i][j] = 1;  // C(i, i) = 1
            } else {
                // 1 <= j < i
                f[i][j] = f[i-1][j] + f[i-1][j-1];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_combinations();  // 预处理组合数

    int n, m, k;
    cin >> n >> m >> k;

    // 统计所有长度为 k 的子串出现次数
    unordered_map<string,int> mp;
    mp.reserve(n * 10);     // 预留一个大概的空间，减少 rehash
    mp.max_load_factor(0.7);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int L = s.size();
        if (L < k) continue;  // 长度不足，就跳过
        for (int st = 0; st + k <= L; st++) {
            // 取得长度为 k 的子串
            string sub = s.substr(st, k);
            mp[sub]++;
        }
    }

    ll ans = 0;
    // 对于每个子串及其出现次数 count
    // 只有当 count >= m 时，我们才真正计算 C(count, m)
    for (auto &entry : mp) {
        int cnt = entry.second;
        if (cnt >= m) {
            // cnt 一定不会超过 INIT_MAX，否则我们就得增大 INIT_MAX
            ll comb = f[cnt][m];  
            // cout << entry.first << " " << cnt << " " << comb << "\n";
            ans += comb;
        }
    }

    // 最终所有符合条件的子串的 C(count,m) 累加结果
    cout << ans << "\n";

    return 0;
}
