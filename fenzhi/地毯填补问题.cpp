#include <iostream>
using namespace std;
//从左上角(a,b)开始处理大小为n×n的迷宫，(x,y)为公主或者已覆盖的位置
void dfs(int a, int b, int x, int y, int n)
{
    if(n == 1) return;
    n = n / 2;
    if(x <= a + n - 1 && y <= b + n - 1) //公主或者已覆盖的位置在左上角，使用1号地毯
    {    
        printf("%d %d 1\n", a + n, b + n);//在障碍物的旁边再加三个障碍物
        dfs(a, b, x, y, n); //公主位置不变
        dfs(a, b + n, a + n - 1, b + n, n);
        dfs(a + n, b, a + n, b + n - 1, n);
        dfs(a + n, b + n, a + n, b + n, n);
    }
    else if(x <= a + n - 1 && y >= b + n) //公主或者已覆盖的位置在右上角，使用2号地毯
    {
        printf("%d %d 2\n", a + n, b + n - 1);
        //分治，分成4个更小的部分递归处理
        dfs(a, b, a + n - 1, b + n - 1, n);
        dfs(a, b + n, x, y, n); //公主位置不变
        dfs(a + n, b, a + n, b + n - 1, n);
        dfs(a + n, b + n, a + n, b + n, n);
    }
    else if(x >= a + n && y <= b + n - 1) //公主或者已覆盖的位置在左下角，使用3号地毯
    {     
        printf("%d %d 3\n", a + n - 1, b + n);
        dfs(a, b, a + n - 1, b + n - 1, n);
        dfs(a, b + n, a + n - 1, b + n, n);
        dfs(a + n, b, x, y, n); //公主位置不变
        dfs(a + n, b + n, a + n, b + n, n);
    }
    else //公主或者已覆盖的位置在右下角，使用4号地毯
    {
        printf("%d %d 4\n", a + n - 1, b + n - 1);
        dfs(a, b, a + n - 1, b + n - 1, n);
        dfs(a, b + n, a + n - 1, b + n, n);
        dfs(a + n, b, a + n, b + n - 1, n);
        dfs(a + n, b + n, x, y, n); //公主位置不变
    }
}
int main()
{
    int x, y, k;
    scanf("%d%d%d", &k, &x, &y);
    int n = 1 << k; //迷宫大小
    dfs(1, 1, x, y, n);
    return 0;
}
