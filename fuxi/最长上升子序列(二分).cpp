#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
int a[N], f[N], pre[N], idx[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // len：当前维护的 LIS 长度
    // f[k]：表示长度为 k 的那些上升子序列中，结尾最小的那个值
    // idx[k]：记录当前长度为 k 时，对应“结尾最小”的那个元素在原数组 a 中的下标
    int len = 0;

    for (int i = 1; i <= n; i++) {
        // 在 f[1..len] 范围内用 lower_bound 寻找第一个 >= a[i] 的位置
        // 注意：查找区间是 [f+1, f+len+1)，所以返回指针可能等于 f+len+1
        int pos = lower_bound(f + 1, f + len + 1, a[i])-f;

        if (pos > len) {
            // 如果 a[i] 比 f[1..len] 都大，就扩展出一个更长的上升子序列
            f[++len] = a[i];
            idx[len] = i;
        } else {
            // 否则就在位置 pos 更新最小的“结尾值”
            f[pos] = a[i];
            idx[pos] = i;
        }

        // 记录 pre[i]：如果 pos > 1，说明当前 a[i] 是某条长度为 pos-1 的子序列的“后继”
        if (pos > 1) {
            pre[i] = idx[pos - 1];
        } else {
            pre[i] = 0;  // pos==1 则没有更短的子序列
        }
    }

    // 下面输出 LIS 的长度；如果只关心长度，这里直接退出即可
    cout << len << "\n";

    // —— 如果需要重构出一条具体的 LIS，可以从 idx[len] 开始沿着 pre[] 回溯 —— 
    vector<int> lis;
    int cur = idx[len];
    while (cur != 0) {
        lis.push_back(a[cur]);
        cur = pre[cur];
    }
    reverse(lis.begin(), lis.end());
    for (int v : lis) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}
