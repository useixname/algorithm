#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int f[N], w[N], v[N];
int n, p, s;

// 在接口大小 = L 时，问最大容量 s 下价值能否 ≥ p
bool chk(int L){
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i++){
        if(w[i] > L) continue;
        for(int j = s; j >= w[i]; j--){
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    return f[s] >= p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> s;
    int maxW = 0;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
        maxW = max(maxW, w[i]);
    }

    int l = 0, r = maxW + 1;
    // 二分查找最小可行 L，区间 (l, r]
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(chk(mid)){
            r = mid;
        } else {
            l = mid;
        }
    }

    // 检查 r 是否可行
    if(r == maxW + 1){
        cout << "No Solution!";
    } else {
        cout << r;
    }
    return 0;
}
