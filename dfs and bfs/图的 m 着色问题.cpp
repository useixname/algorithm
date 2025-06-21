#include<bits/stdc++.h>
using namespace std;

bool f[105][105];
int color[105];
int num;
int n, k, m;

bool check(int sum)
{
    for (int i = 1; i <= sum; i++)
    {
        if (f[i][sum] == true && color[i] == color[sum])
        {
            return false;
        }
    }
    return true;
}

void dfs(int s)
{
    if (s > n)
    {
        num++;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        color[s] = i;
        if (check(s) == true)
        {
            dfs(s + 1);
        }
        else
        {
            color[s] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        f[x][y] = true;
        f[y][x] = true;
    }
    memset(color, 0, sizeof(color));
    dfs(1);
    cout << num << endl;
    return 0;
}