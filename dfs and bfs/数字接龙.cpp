#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 搜索常用，遍历八个方向

int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int k, n;

bool ac = false; // 非常重要，用来解决字典需最小

vector<int> now, res;

int e[N][N]; // 地图

bool st[N][N]; // 记录是否走过

void dfs(int x, int y, int cnt)
{

    if (ac)
        return;

    if (x == n && y == n && now.size() == (n * n - 1))
    { // 这里重点，找到一次就可以输出了

        ac = true;

        res = now;

        return;
    }

    int nxp = cnt % k;

    for (int i = 0; i < 8; ++i)
    {

        int nx = x + dx[i];

        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > n || st[nx][ny])
            continue; // 不符合的条件出界和已经访问过

        if (e[nx][ny] != nxp)
            continue; // 当前走的位置不符合地图上的数字

        if (i == 1 && st[x - 1][y] == 1 && st[x][y + 1] == 1)
            continue;

        if (i == 3 && st[x + 1][y] == 1 && st[x][y + 1] == 1)
            continue;

        if (i == 5 && st[x + 1][y] == 1 && st[x][y - 1] == 1)
            continue;

        if (i == 7 && st[x - 1][y] == 1 && st[x][y - 1] == 1)
            continue;

        st[nx][ny] = true; // 标记

        now.push_back(i);

        dfs(nx, ny, cnt + 1);

        now.pop_back();

        st[nx][ny] = false;
    }
}

int main()
{

    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {

        for (int j = 1; j <= n; ++j)
        {

            cin >> e[i][j];
        }
    }

    st[1][1] = true; //

    dfs(1, 1, 1);

    if (res.size() == 0)
        cout << -1 << endl;

    else
    {

        for (int i = 0; i < res.size(); ++i)
            cout << res[i];

        cout << endl;
    }

    return 0;
}