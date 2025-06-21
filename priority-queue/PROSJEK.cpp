#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // 读取输入数组
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 计算前缀和数组
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    // 单调队列
    deque<int> dq;
    double maxAvg = -1e9;

    // 遍历每一个可能的右端点
    for (int i = k; i <= n; i++) {
        // 清理队列，保证队列中始终保持前缀和最小值的索引
        while (!dq.empty() && prefix[dq.back()] >= prefix[i - k]) {
            dq.pop_back();
        }

        // 加入当前元素
        dq.push_back(i - k);

        // 计算当前子数组的平均值
        double avg = (prefix[i] - prefix[dq.front()]) * 1.0 / (i - dq.front());

        // 更新最大平均值
        maxAvg = max(maxAvg, avg);
    }

    // 输出结果
    cout << maxAvg << endl;

    return 0;
}
