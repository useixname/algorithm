#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k, tail, head, ans[N];
unsigned long long stk[N];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%llu", stk + i);
        if (head - tail && ans[tail + 1] + k <= i)
            tail++;
        while (head - tail && stk[ans[head]] <= stk[i])
            head--;
        ans[++head] = i;
        if (i >= k)
            printf("%d\n", head - tail);
    }
    return 0;
}