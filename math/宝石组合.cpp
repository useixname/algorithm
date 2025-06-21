#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int h[N], cnt[N];  // h 数组存储输入的数，cnt 数组记录每个数作为约数出现的次数

int main() {
    int n, x, c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];  // 读取数组元素
        // 查找 h[i] 的所有约数
        for (int j = 1; j * j <= h[i]; j++) {
            if (h[i] % j == 0) {  // 如果 j 是 h[i] 的约数
                cnt[j]++;  // 记录 j 是一个约数
                if (j * j != h[i]) cnt[h[i] / j]++;  // 如果 j 不是平方根，记录 h[i] / j 也是约数
            }
        }
    }
    
    // 从大到小查找至少出现了三次的最大约数
    for (int i = N - 5; i >= 1; i--) {
        if (cnt[i] >= 3) {
            x = i;  // 找到符合条件的最大约数
            break;
        }
    }

    sort(h + 1, h + n + 1);  // 将 h 数组排序
    for (int i = 1; i <= n; i++) {
        if (h[i] % x == 0) {  // 如果 h[i] 能被 x 整除
            cout << h[i] << " ";  // 输出符合条件的数
            c++;
        }
        if (c == 3) return 0;  // 输出 3 个数后退出
    }
    
    return 0;
}
