#include <iostream>
#include <vector>
using namespace std;


//-1 -2 0 1 2
// 4  3 0 1 2

//-1 0 1
// 2 0 1
// 将正整数 n 转换为平衡三进制，返回每一位的系数（-1, 0, 1）
vector<int> balancedTernary(int n) {
    vector<int> digits;
    while (n != 0) {
        int r = n % 3;
        if (r == 2) {
            digits.push_back(-1);
            n = (n + 1) / 3;
        } else {
            digits.push_back(r);
            n = (n - r) / 3;
        }
    }
    return digits;
}

int main() {
    int n;
    if (!(cin >> n) || n < 1 || n > 121) return 0;
    vector<int> weights = {1, 3, 9, 27, 81};
    vector<int> coeffs = balancedTernary(n);
    
    // 收集结果：按重量降序排列输出
    bool first = true;
    for (int i = weights.size() - 1; i >= 0; --i) {
        int w = weights[i];
        int c = (i < coeffs.size() ? coeffs[i] : 0);
        if (c == 0) continue;
        if (first) {
            // 首项，不输出 '+'
            if (c == -1) cout << '-';
            cout << w;
            first = false;
        } else {
            // 后续项，输出 '+' 或 '-'
            cout << (c == 1 ? '+' : '-') << w;
        }
    }
    return 0;
}