#include <bits/stdc++.h>
using namespace std;

// 拆分输入字符串（按大写字母开头分段，小写字母不分割）
void splitByUppercase(const string &s, vector<string> &raw, vector<string> &sorted) {
    int n = s.size();
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            // 从 start 到 i-1 是一个片段
            raw.push_back(s.substr(start, i - start));
            sorted.push_back(s.substr(start, i - start));
            start = i;
        }
    }
    // 最后一段
    raw.push_back(s.substr(start, n - start));
    sorted.push_back(s.substr(start, n - start));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // 1. 按“大写字母开头”拆分成若干子串，保存在 raw 中
    vector<string> raw, sorted;
    raw.reserve(s.size());
    sorted.reserve(s.size());
    splitByUppercase(s, raw, sorted);

    int cnt = (int)raw.size();
    if (cnt == 0) {
        // 若输入为空字符串，直接结束
        return 0;
    }

    // 2. 对 sorted 进行字典序排序
    sort(sorted.begin(), sorted.end());
    // （可选）如果要把相同片段去重，可取消下面两行注释：
    // sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    // 3. 构造 b[i] 数组：原来第 i 个拆分片段 raw[i-1] 在排序后的位置（下标 + 1）
    vector<int> b(cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        int pos = int(lower_bound(sorted.begin(), sorted.end(), raw[i - 1]) - sorted.begin());
        b[i] = pos + 1;  // 1-based 编号
    }

    // 4. 在 b[1..cnt] 上求最长严格递增子序列（LIS），并记录前驱 pre[i]
    //    使用 O(n log n) 方法：维护 tail[] 与 idx[]，其中 tail[k] 是长度为 k+1 的递增子序列的最小“结尾值”；
    //    idx[k] 存储该子序列真实在 b 中的下标。
    vector<int> tail;            // 存放 “各长度 LIS 的最小结尾值”
    vector<int> idx;             // idx[k] = 末尾元素在原序列 b 中的下标 (1..cnt)
    vector<int> pre(cnt + 1, 0); // pre[i] 用于重建路径

    for (int i = 1; i <= cnt; i++) {
        int x = b[i];
        // 在 tail 中二分查找第一个 >= x 的位置 p
        int p = int(lower_bound(tail.begin(), tail.end(), x) - tail.begin());
        if (p == (int)tail.size()) {
            // x 比所有 tail 元素都大，可以扩展出更长的 LIS
            tail.push_back(x);
            idx.push_back(i);
        } else {
            // 用 x 更新 tail[p]
            tail[p] = x;
            idx[p] = i;
        }
        // 如果 p > 0，则前驱就是 idx[p-1]
        if (p > 0) {
            pre[i] = idx[p - 1];
        } else {
            pre[i] = 0; // 长度为 1 的 LIS，pre = 0 表示无前驱
        }
    }

    // 5. 重建 LIS 路径
    int lis_length = (int)tail.size();
    int last_idx = idx.back(); // LIS 最后一个元素在 b 中的下标
    vector<string> answer;
    answer.reserve(lis_length);
    while (last_idx != 0) {
        answer.push_back(raw[last_idx - 1]);
        last_idx = pre[last_idx];
    }
    reverse(answer.begin(), answer.end());

    // 6. 输出将各片段拼接成一个字符串
    for (auto &seg : answer) {
        cout << seg;
    }
    cout << "\n";

    return 0;
}
