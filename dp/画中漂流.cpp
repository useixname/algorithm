#include <bits/stdc++.h> 
using namespace std;
const int mod = 1e9 + 7;
int f[3030][3030];
int d, t, m;

int main(){
    cin >> d >> t >> m;
    f[0][m] = 1;
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j <= m; ++j) {
            int len = d + (m - j) - (i - (m - j));
            if (len > 0) {
                f[i][j] = (f[i - 1][j] + f[i - 1][j + 1]) % mod;
            }
        }
    }
    cout << f[t][0] << endl;
    return 0;
}