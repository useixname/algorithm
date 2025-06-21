#include <bits/stdc++.h>
using namespace std;

static const double INF = 1e18;
double dp[505][505][2];
double a[505], b[505];

int main(){
    int l, r;
    double d, w;
    cin >> l >> r >> d >> w;

    // 1) 读入左右两岸坐标
    for(int i = 1; i <= l; i++) cin >> a[i];
    for(int j = 1; j <= r; j++) cin >> b[j];

    // 2) “显式”把 a[0], b[0] 设为 0，避免后面 i=1 或 j=1 时用到未初始化下标
    a[0] = 0.0;
    b[0] = 0.0;

    // 3) 初始化 dp 全部为 INF
    for(int i = 0; i <= l; i++){
        for(int j = 0; j <= r; j++){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }

    // 4) 边界：只到左岸第 1 个点
    dp[1][0][0] = sqrt( (w/2)*(w/2) + a[1]*a[1] );
    // 只到右岸第 1 个点
    dp[0][1][1] = sqrt( (w/2)*(w/2) + b[1]*b[1] );

    // 5) 逐步 DP
    for(int i = 0; i <= l; i++){
        for(int j = 0; j <= r; j++){
            if(i > 0){
                // 从左岸 (i-1, j, 停在左岸) → (i, j, 停在左岸)
                dp[i][j][0] = min(
                    dp[i][j][0],
                    dp[i-1][j][0] + (a[i] - a[i-1])
                );
                // 从右岸 (i-1, j, 停在右岸) → (i, j, 停在左岸) （跨河）
                dp[i][j][0] = min(
                    dp[i][j][0],
                    dp[i-1][j][1]
                      + sqrt( (a[i] - b[j])*(a[i] - b[j]) + w*w )
                );
            }
            if(j > 0){
                // 从右岸 (i, j-1, 停在右岸) → (i, j, 停在右岸)
                dp[i][j][1] = min(
                    dp[i][j][1],
                    dp[i][j-1][1] + (b[j] - b[j-1])
                );
                // 从左岸 (i, j-1, 停在左岸) → (i, j, 停在右岸) （跨河）
                dp[i][j][1] = min(
                    dp[i][j][1],
                    dp[i][j-1][0]
                      + sqrt( (b[j] - a[i])*(b[j] - a[i]) + w*w )
                );
            }
        }
    }

    // 6) 最后一步：从左岸 l→(d,0) 或 右岸 r→(d,0)
    double toEndFromLeft = sqrt( (d - a[l])*(d - a[l]) + (w/2)*(w/2) );
    double toEndFromRight= sqrt( (d - b[r])*(d - b[r]) + (w/2)*(w/2) );
    double ans = min(
        dp[l][r][0] + toEndFromLeft,
        dp[l][r][1] + toEndFromRight
    );

    cout << fixed << setprecision(2) << ans << "\n";
    return 0;
}
