#include <bits/stdc++.h>
using namespace std;

int change_num(char p)
{
    switch (p)
    {
    case 'A':
        return 1;
    case 'T':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    default:
        return int(p - '0');
    }
}

int n, ans;
set<char> color[14];
int cnt[14];

int main()
{
    char a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %c%c", &a, &b);
        int t = change_num(b);
        cnt[t]++;
        color[t].insert(a);
    }
    for (int i = 1; i <= 13; i++)
    {
        if (cnt[i] == 5)
            ans++;
        else if (cnt[i] >= 6)
            ans += 2;
        else if (cnt[i] >= 3 && cnt[i] <= 4 && (int)color[i].size() != cnt[i])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}