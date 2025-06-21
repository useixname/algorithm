#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, fa[250], tot;

struct edge
{
    int a, b;
    bool operator<(const edge & pa) const{
        if(a==pa.a) return b<pa.b;
        return a<pa.a;
    }
} e[5200];

void init(){
    tot=0;
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
}
int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void join(int x, int y)
{
    int a = find(x), b = find(y);
    if (a != b)
        fa[a] = b, tot++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &e[i].a, &e[i].b);
        if (e[i].a > e[i].b)
            swap(e[i].a, e[i].b);
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++)
    {
        init();
        for (int j = 1; j <= m; j++)
        {
            if (i != j)
                join(e[j].a, e[j].b);
            if (tot == n - 1)
                break;
        }
        if (tot != n - 1)
            printf("%d %d\n", e[i].a, e[i].b);
    }
    return 0;
}