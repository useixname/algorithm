#include <cstdio>
typedef long long LL;
const LL INF = 1e18; // 使用更大的 INF，避免组合数计算时的溢出
LL n;

// 计算 C(a, b) 即组合数 C(a, b) = a! / (b! * (a-b)!)
LL C(LL a, LL b) {
    LL res = 1;
    for (LL i = a, j = 1; j <= b; i--, j++) {
        res = res * i / j;
        if (res > n)  // 如果已经大于 n，直接返回
            return res;
    }
    return res;
}

int main() {
    scanf("%lld", &n);
    // 只需遍历 16 行
    if (n == 1) {
        printf("1");
        return 0;
    }

    // 二分查找
    for (int i = 16; i >= 0; i--) {
        LL l = 2 * i, r = INF, mid, lim;
        while (l <= r) {
            mid = (l + r) >> 1;  // 计算中间值
            lim = C(mid, i);  // 计算组合数
            if (lim == n) {  // 找到满足条件的组合数
                printf("%lld", (mid + 1) * mid / 2 + i + 1);
                return 0;
            } else if (lim < n) {  // 组合数小于 n，继续寻找
                l = mid + 1;
            } else {  // 组合数大于 n，缩小范围
                r = mid - 1;
            }
        }
    }

    return 0;
}
