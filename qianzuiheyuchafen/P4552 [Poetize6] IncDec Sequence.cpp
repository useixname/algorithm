#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    ll prev, cur;
    cin >> prev;
    ll P = 0, M = 0;
    for (int i = 2; i <= n; i++) {
        cin >> cur;
        ll diff = cur - prev;
        if (diff > 0) P += diff;
        else M += -diff;
        prev = cur;
    }
    ll ops = max(P, M);
    ll count = llabs(P - M) + 1;
    cout << ops << '\n' << count << '\n';
    return 0;
}
