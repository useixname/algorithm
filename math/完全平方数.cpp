#include <iostream>
#include <cmath>
#include <unordered_map>
#define int long long
using namespace std;
// 获取 n 的质因数分解
unordered_map<int, int> getPrimeFactors(int n) {
    unordered_map<int, int> factors;
    
    // 处理 2 的幂次
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    // 如果 在sqrt(n)内没有找到任何因子，那么 n 本身就应该是一个质数。
    // 处理其他质数因子
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    
    // 如果 n 本身是一个大于 2 的质数
    if (n > 2) {
        factors[n]++;
    }
    
    return factors;
}

// 找到最小的 x 使得 n * x 是完全平方数
int smallestXForSquare(int n) {
    unordered_map<int, int> factorCounts = getPrimeFactors(n);
    int x = 1;
    
    // 检查每个质因子的幂次
    for (const auto& factor : factorCounts) {
        if (factor.second % 2 != 0) {  // 如果幂次是奇数
            x *= factor.first;         // 乘以该质因数
        }
    }
    
    return x;
}

signed main() {
    int n;
    cin >> n;

    int x = smallestXForSquare(n);
    cout << x << endl;

    return 0;
}
