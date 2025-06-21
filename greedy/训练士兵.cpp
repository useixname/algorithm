#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;

LL n, s;        // n 为士兵数量, s 为组团训练费用
LL p[N], c[N];  // p[i] 是训练花费，c[i] 是所需训练次数
LL cnt[N];      // 记录每个训练次数 `c[i]` 的总金币需求
LL Sum = 0;     // 所有士兵单独训练的总金币需求
LL now = 0;     // 当前士兵训练的金币消耗
LL ans = 0;     // 计算的最终最小金币需求

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];   // 读取士兵的训练花费和需求
        cnt[c[i]] += p[i];     // 统计每个训练次数 `c[i]` 对应的金币需求
        now += p[i];           // 当前所有士兵的训练金币需求
        Sum += p[i] * c[i];    // 计算所有士兵的单独训练总成本
    }

    // 从小的训练次数开始考虑组团训练
    for (int i = 1; i <= 1e6; i++) {
        if (now < s)  break;   // 如果当前训练总金币需求 `now` 已经低于 `s`，就不再组团训练
        ans += s;              // 购买一次组团训练
        Sum -= now;            // 由于组团训练，每个士兵都少训练一次，因此减少金币 `now`
        now -= cnt[i];         // 训练次数为 `i` 的士兵，他们的训练需求减少
    }

    cout << ans + Sum;         // 计算最终的最小花费
    return 0;
}
