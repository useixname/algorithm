#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;

struct point {
    int x, y;
} a[N];

int n, ans;

int dist(point &p1, point &p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool valid_triangle(point &p1, point &p2, point &p3) {
    // 判断三点不共线（叉积不为0）
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x) != 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;

    for(int i = 1; i <= n; i++) {
        map<int, vector<int>> mp;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            int d = dist(a[i], a[j]);
            mp[d].push_back(j);
        }

        for(auto &[d, vec] : mp) {
            int sz = vec.size();
            for(int x = 0; x < sz; x++) {
                for(int y = x + 1; y < sz; y++) {
                    int j = vec[x], k = vec[y];
                    if (valid_triangle(a[i], a[j], a[k])) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
