#include <iostream>
using namespace std;
const int N = 5e3 + 5, mod = 998244353;
int f[2][N][8];
char a[N];
int n, k;
signed main()
{
    cin >> n >> k;

    cin >> a + 1;

    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {

            if (a[i] == '0')
            {
                f[1][j][0] = (f[0][j][0] + f[0][j][4]) % mod;
                f[1][j][2] = (f[0][j][1] + f[0][j][5]) % mod;
                f[1][j][4] = (f[0][j][2]) % mod;
                f[1][j][6] = 0;
                if (j)
                {
                    f[1][j][1] = (f[0][j - 1][0] + f[0][j - 1][4]) % mod;
                    f[1][j][3] = (f[0][j - 1][1] + f[0][j - 1][5]) % mod;
                    f[1][j][5] = (f[0][j - 1][2]) % mod;
                    f[1][j][7] = (f[0][j - 1][3] + f[0][j - 1][7]) % mod;
                }
            }
            else
            {
                f[1][j][1] = (f[0][j][0] + f[0][j][4]) % mod;
                f[1][j][3] = (f[0][j][1] + f[0][j][5]) % mod;
                f[1][j][5] = (f[0][j][2]) % mod;
                f[1][j][7] = (f[0][j][3] + f[0][j][7]) % mod;
                if (j)
                {

                    f[1][j][0] = (f[0][j - 1][0] + f[0][j - 1][4]) % mod;
                    f[1][j][2] = (f[0][j - 1][1] + f[0][j - 1][5]) % mod;
                    f[1][j][4] = (f[0][j - 1][2]) % mod;
                    f[1][j - 1][6] = 0;
                }
            }
        }
        for (int j = 0; j <= k; j++)
        {
            for (int k = 0; k <= 7; k++)
            {
                f[0][j][k] = f[1][j][k];
                f[1][j][k] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= 7; j++)
            ans = (ans + f[0][i][j]) % mod;
    }
    cout << ans % mod;
    return 0;
}