#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
using LL = long long;

constexpr int N = 5e3 + 1;
constexpr int MOD = 1e9 + 7;
char s[N];
int n;

LL f()
{
    // dp[i][j] 包含到s[i]的子串，且(添加完之后)左括号比右括号多j个时 
    // 添加的左括号的方案总数目 
    vector<vector<LL>> dp(n + 1, vector<LL>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') {
            // 此时添加左括号无意义
            for (int j = 1; j <= n; ++j) 
                // 右式表示前面字串(不包含当前字符)中左括号比右括号多j-1个时
                // 添加的左括号数目，递推到左式，由于当前又是一个左括号，所以
                // 到当前的字串左括号比右括号多j个 
                dp[i][j] = dp[i - 1][j - 1];
        } else {
            // dp[i][j] 前一状态(i-1)左括号比右括号最多多j+1个
            // 此时再算上当前一个右括号，使得左括号比右括号多j个，此时添加0个左括号
            // 同理 当前一状态多j个时，再添加1个左括号...多0个时，添加j+1个(当前有一个右括号) 
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            for (int j = 1; j <= n; ++j)
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }
    // 取最少的情况 
    for (auto& v : dp[n]) 
        if (v) return v;
    return 0;
}

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    LL l = f();
    reverse(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i) 
        if (s[i] == '(') s[i] = ')';
        else s[i] = '(';
    LL r = f();
    printf("%lld", l * r % MOD);
    return 0;
}