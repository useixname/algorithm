#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
vector<pair<int, pair<int, int>>> ranges; // 保存区间 [start, end] 和对应的数值
int n, q, t = 1;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++, t++) {
        cin >> a[i];
        int start = t;
        if (a[i] % 2 == 0) {
            int x = a[i], k = 0;
            while (x % 2 == 0) {
                x /= 2;
                k++;
            }
            t += (1LL << k) - 1; // 1LL << k 等价于 pow(2, k)
            ranges.push_back({start, {t, x}}); // 保存区间 [start, t] 和对应的数值 x
        } else {
            ranges.push_back({start, {t, a[i]}});
        }
    }

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        
        // 二分查找找到区间范围
        int l = 0, r = ranges.size() - 1, ans = -1;
        int y=lower_bound(ranges.begin(),ranges.end(),x)-ranges.begin();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ranges[mid].first <= x && x <= ranges[mid].second.first) {
                ans = ranges[mid].second.second;
                break;
            } else if (x < ranges[mid].first) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
