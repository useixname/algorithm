#include <bits/stdc++.h>
using namespace std;
const int N = 4010;
int f[N], w[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> w[1] >> w[2] >> w[3];

    // 用 -1 表示不可达
    memset(f, -1, sizeof(f));
    f[0] = 0;

    // 三种长度，做完全背包
    for (int i = 1; i <= 3; i++) {
        for (int j = w[i]; j <= n; j++) {
            if (f[j - w[i]] != -1) {
                f[j] = max(f[j], f[j - w[i]] + 1);
            }
        }
    }

    cout << f[n] << "\n";
    return 0;
}
