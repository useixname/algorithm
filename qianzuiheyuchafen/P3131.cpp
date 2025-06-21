#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 10;

int a[N], sum[N];
vector<int> q[7];
int n, ans;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    // 把前缀和下标 0 放进去，便于处理从头开始的区间
    q[0].push_back(0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        int x = sum[i] % 7;
        q[x].push_back(i);
    }
    for(int i = 0; i < 7; i++){
        if(q[i].size() >= 2){
            // q[i] 本身就是从小到大插入，无需再 sort，但 sort 也不影响复杂度
            ans = max(ans, q[i].back() - q[i].front());
        }
    }
    cout << ans << "\n";
    return 0;
}
