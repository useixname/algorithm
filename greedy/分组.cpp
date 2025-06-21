#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, a[N];
int q[N], siz[N], cnt;
// q[k]第k组的最大实力值
// siz[k]第k组的人数
// cnt记录组数

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    q[0] = 2e9; // 保证k==0时，新开一组
    for (int i = 1, k; i <= n; i++)
    {
        // 找到小于等于 a[i]-1 的最后一组
        k = upper_bound(q + 1, q + cnt + 1, a[i] - 1) - q - 1;
        if (q[k] == a[i] - 1)
            q[k] = a[i], siz[k]++; // 接入第k组
        else
            q[++cnt] = a[i], siz[cnt] = 1; // 新开一组
    }

    int ans = 1e9;
    for (int i = 1; i <= cnt; i++)
        ans = min(ans, siz[i]);
    printf("%d\n", ans);
    return 0;
}