#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;

// 全局数组：
// g[][] 存储输入的矩阵，矩阵尺寸为 n×m，题目中 n,m 会在输入时确定
int g[N][N];
// rmax[][] 用于存储每一行中，滑动窗口（连续 B 列）内的最大值；
// rmin[][] 用于存储每一行中，滑动窗口内的最小值。
int rmax[N][N] , rmin[N][N];
// q[] 为双端队列（deque）的临时数组，用于滑动窗口处理（维护单调队列）
int q[N];

int n, m, k, ans = INT_MAX;

// low_bit 函数返回 x 的最低有效位（即 x & -x），用于树状数组或滑动窗口更新中
int low_bit(int x){
    return x & -x;
}
 
// get_max 函数：对数组 a[]（长度为 tot）进行滑动窗口最大值处理，窗口宽度为 k
// 最终将每个位置的窗口最大值保存在数组 b[] 中。
// 原理：利用双端队列技术，队列 dq 用 q[] 表示，维护窗口 [i-k+1, i] 中元素 a[] 的值单调递减，队首即为窗口最大值。
void get_max(int a[] , int b[] , int tot , int k)
{
    int hh = 0, tt = -1; // hh: 队首指针，tt: 队尾指针（初始化为空队列）
    for(int i = 0; i < tot; i++){
        // 如果队列不空且当前窗口已经滑出队列左侧，则将队首弹出
        if(hh <= tt && i - k + 1 > q[hh])
            hh++;
        // 保持队列单调递减：当队尾元素对应的值小于等于 a[i] 时，弹出队尾
        while(hh <= tt && a[q[tt]] <= a[i])
            tt--;
        // 将当前下标 i 加入队列尾部
        q[++tt] = i;
        // 当前窗口 [i - k + 1, i] 的最大值为 a[q[hh]]，记录在 b[i] 中
        b[i] = a[q[hh]];
    }
}
 
// get_min 函数：对数组 a[]（长度为 tot）进行滑动窗口最小值处理，窗口宽度为 k
// 最终将每个位置窗口内的最小值存入数组 b[] 中。
// 原理同 get_max，不过这里维护单调递增队列，队首对应窗口最小值。
void get_min(int a[] , int b[] , int tot , int k)
{
    int hh = 0, tt = -1;
    for(int i = 0; i < tot; i++){
        // 检查队首是否已经滑出当前窗口
        if(hh <= tt && i - k + 1 > q[hh])
            hh++;
        // 保持队列单调递增：弹出队尾所有大于等于 a[i] 的元素
        while(hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        // 队首即为窗口最小值
        b[i] = a[q[hh]];
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k; // 输入矩阵行数 n、列数 m 和参数 k
    // 读入 n×m 的矩阵，存入 g[][]（下标从0开始）
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    
    // 对于每一行，利用滑动窗口计算连续 B 列内的最大值和最小值
    // rmax[i][j] 表示第 i 行，在窗口末尾位置 j 的窗口中（窗口大小为 B）的最大值
    // rmin[i][j] 表示第 i 行，在窗口末尾位置 j 的窗口中最小值
    for(int i = 0; i < n; i++){
        // 对于第 i 行，调用 get_max 和 get_min
        // 参数：数组 g[i]、输出数组 rmax[i]（或 rmin[i]）、总列数 m、窗口宽度 B
        get_max(g[i], rmax[i], m, k);
        get_min(g[i], rmin[i], m, k);
    }
    
    // 下面的循环用于处理子矩阵：以每个可能的右边界列 j (从 B-1 到 m-1) 作为终点，
    // 然后对每列的 rmax 和 rmin 数组，再利用滑动窗口在行方向上求窗口大小为 A 行（这里 A 用 k 表示，因为题目描述可能使用 A）内的最大值和最小值，
    // 最后计算子矩阵稳定度（即最大值减最小值），并更新 ans 为所有子矩阵中稳定度的最小值。
    int a[N], b[N], c[N];
    int res = 0;
    
    // 枚举列方向窗口的右边界 j，从 B-1 到 m-1（窗口大小为 B 列）
    for(int j = k - 1; j < m; j++){
        // 对于每行，构造数组 a[]，表示第 i 行窗口内的最大值：即 rmax[i][j]
        for(int i = 0; i < n; i++){
            a[i] = rmax[i][j];
        }
        // 在行方向上，对数组 a[] 进行滑动窗口最大值处理，窗口大小为 A 行（这里 A 用 k 表示，可能和题目描述有关）
        // 结果存入数组 b[]
        get_max(a, b, n, k);
        
        // 同理，构造数组 a[] 表示第 i 行窗口内的最小值：即 rmin[i][j]
        for(int i = 0; i < n; i++){
            a[i] = rmin[i][j];
        }
        // 对数组 a[] 进行滑动窗口最小值处理，窗口大小为 A 行，结果存入数组 c[]
        get_min(a, c, n, k);
        
        // 对于每个可能的行窗口，当行窗口恰好为 k 行（即 i 从 k-1 到 n-1），计算稳定度：
        // 稳定度 = b[i] - c[i]，取最小值更新 ans
        for(int i = k - 1; i < n; i++){
            res = (res + b[i] * c[i]) % 998244353;
        }
    }
    
    // 此处代码中 res 被累加而非取最小值，具体含义可能取决于题目要求，
    // 但原代码中 ans 最终输出的是 ans（初始为 INT_MAX），此处示例输出 res
    cout << res;
    return 0;
}
