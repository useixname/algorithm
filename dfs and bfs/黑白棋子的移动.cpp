#include <iostream>
using namespace std;
int n, st, sp;
char c[210];
void print() // 打印
{
    int i;
    for (i = 1; i <= 2 * n + 2; i++)
        cout << c[i];
    cout << endl;
    st++;
}
void init(int n) // 初始化
{
    int i;
    st = 0;
    sp = 2 * n + 1;
    for (i = 1; i <= n; i++)
        c[i] = 'o';
    for (i = n + 1; i <= 2 * n; i++)
        c[i] = '*';
    c[2 * n + 1] = '-';
    c[2 * n + 2] = '-';
    print();
}
void move(int k) // 移动一步
{
    int j;
    for (j = 0; j <= 1; j++)
    {
        c[sp + j] = c[k + j];
        c[k + j] = '-';
    }
    sp = k;
    print();
}
void mv(int n) // 主要过程
{
    int i, k;
    if (n == 4) // n等于4的情况要特殊处理
    {
        move(4);
        move(8);
        move(2);
        move(7);
        move(1);
    }
    else
    {
        move(n);
        move(2 * n - 1);
        mv(n - 1);
    }
}
int main()
{
    cin >> n;
    init(n);
    mv(n);
}