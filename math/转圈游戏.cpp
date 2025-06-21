#include <cstdio>
using namespace std;
int n, m, k, x;

int q_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % n;
        b >>= 1;
        a = (a * a) % n;
    }
    return ans % n;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &x);
    printf("%d", (x % n + m * q_pow(10, k)) % n);
    return 0;
}