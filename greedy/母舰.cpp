#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tf[10000000], wf[10000000];
int m, n, s, i, t;
int main()
{
    cin >> m >> n;
    for (i = 1; i <= m; i++)
        scanf("%d", &tf[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &wf[i]);
    sort(tf + 1, tf + 1 + m);
    sort(wf + 1, wf + 1 + n);
    t = 1;
    for (i = 1; i <= n; i++)
    {
        if (tf[t] == 0)
            t++;
        if (tf[t] < wf[i] && tf[t] != 0)
        {
            wf[i] = 0;
            t++;
        }
    }
    if (t <= m)
    {
        cout << 0;
        return 0;
    }
    for (i = 1; i <= n; i++)
        s += wf[i];
    cout << s;
}