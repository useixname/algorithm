#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 200010;
struct Point
{
    double x, y;
} a[N], b[N];

bool cmp(Point &a, Point &b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
double dis(Point &a, Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double divide(int l, int r)
{
    double d = 2e9;
    if (l == r)
        return d;
    int m = (l + r) >> 1;
    Point tmp = a[m];
    d = min(divide(l, m), divide(m + 1, r));

    int i = l, j = m + 1, k = 0, t = 0;
    while (i <= m && j <= r)
        if (a[i].y < a[j].y)
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (i = l, j = 0; i <= r;)
        a[i++] = b[j++];

    for (i = 0; i < k; i++)
        if (fabs(tmp.x - b[i].x) < d)
            b[t++] = b[i];

    for (i = 0; i < t; i++)
        for (j = i + 1; j < t && b[j].y - b[i].y < d; j++)
            d = min(d, dis(b[j], b[i]));
    return d;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1, cmp);
    printf("%.4lf\n", divide(1, n));
}