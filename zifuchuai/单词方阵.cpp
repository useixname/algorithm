#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int net[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
char a[N][N], b[N][N];
string s = "yizhong*";
int n;

bool chk(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int step = 1;
        int tx = x + net[i][0], ty = y + net[i][1];
        while ((tx >= 1 && tx <= n && ty >= 1 && ty <= n) && (a[tx][ty] == s[step]))
        {
            step++;
            tx += net[i][0], ty += net[i][1];
        }
        if (step == 7)
        {
            for (int j = 1; j <= 7; j++)
            {
                b[x][y] = a[x][y];
                x += net[i][0];
                y += net[i][1];
            }
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    memset(b, '*', sizeof(b));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == s[0])
            {
                chk(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << b[i][j];
        }
        cout << '\n';
    }
    return 0;
}