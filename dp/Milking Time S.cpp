#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct interval
{
    int l, r, w;
} itv;

itv v[1010];
int n, m, r, d[1010] = {0}, ans = 0;

inline int read()
{
    int num = 0, k = 1;
    char c = getchar();
    while (c > '9' || c < '0')
        k = (c == '-') ? -1 : k, c = getchar();
    while (c >= '0' && c <= '9')
        num = (num << 3) + (num << 1) + c - '0', c = getchar();
    return num * k;
}

bool cmp(itv a, itv b) { return a.l < b.l; } // 这个地方写 a.r<b.r 也可以

int main()
{
    n = read();
    m = read();
    r = read();
    for (int i = 1; i <= m; i++)
        v[i].l = read(), v[i].r = read() + r, v[i].w = read();
    // 直接在区间右端加上r，方便后面处理
    sort(v + 1, v + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        for (int j = i - 1; j >= 1; j--)
            if (v[j].r <= v[i].l) // 保证两个区间不相交
                d[i] = max(d[i], d[j]);
        d[i] += v[i].w;
        ans = max(ans, d[i]);
    }
    printf("%d", ans);
    return 0;
}