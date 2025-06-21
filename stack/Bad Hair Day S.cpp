#include <bits/stdc++.h>
using namespace std;

int n, t;
long long ans; // 需要 long long 以防溢出
stack<int> a;  // 维护单调递减栈

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); // 加速 I/O

    cin >> n;
    while (n--) {  // 直接循环 n 次
        cin >> t;
        while (!a.empty() && a.top() <= t) {  
            a.pop();  // 移除被挡住的牛
        }
        ans += a.size();  // 统计当前牛能看到的数量  0 1 1 2 0 1
        a.push(t);  // 当前牛入栈
    }
    // 10 3 7 4 12 2
    // 10,10 3,10 7,10 7 4,12,12 2 
    cout << ans << "\n";
    return 0;
}
