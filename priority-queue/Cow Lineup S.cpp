#include<bits/stdc++.h>
using namespace std;

// 定义 node 结构体
struct node {
    int x;  // 记录数值
    int p;  // 记录类型标识
};

node s[70000];  // 数组 s 存储所有的 (x, p) 对
int ans = 2e9, sum, n, z, tail;
map<int, int> t;  // 用于记录当前窗口中每个 p 的出现次数
map<int, bool> pan;  // 用于去重 p 值
bool cmp(node a, node b) {  // 自定义排序规则，按照 x 值排序
    return a.x < b.x;
}

int main() {
    cin >> n;  // 输入数组的大小
    for (int i = 1; i <= n; i++) {
        cin >> s[i].x >> s[i].p;  // 输入每个 (x, p) 对
        if (pan[s[i].p] == false) {  // 如果 p 是新的，记录下来
            sum++;  // 统计不同 p 值的个数
            pan[s[i].p] = true;
        }
    }

    sort(s + 1, s + n + 1, cmp);  // 按照 x 进行排序

    tail = 1;  // 初始 tail 指针
    t[s[1].p]++;  // 将第一个元素的 p 值计入窗口
    z = 1;  // 当前窗口中的不同 p 值个数
    for (int i = 1; i <= n; i++) {
        // 扩展窗口，直到窗口中包含所有不同的 p 值
        while (z < sum && tail < n) {
            tail++;  // 扩展窗口右边界
            t[s[tail].p]++;  // 记录当前 p 值
            if (t[s[tail].p] == 1) z++;  // 如果当前 p 是第一次出现，增加不同 p 的数量
        }

        // 如果窗口中包含所有不同的 p 值，更新最小长度
        if (z == sum) ans = min(ans, s[tail].x - s[i].x); 

        // 收缩窗口，移除左边界的元素
        t[s[i].p]--;
        if (t[s[i].p] == 0) z--;  // 如果移除的 p 值的数量为 0，减少不同 p 的数量
    }

    cout << ans;  // 输出最小子数组的长度
    return 0;
}
