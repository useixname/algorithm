#include<bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;

const int N = 3e5 + 5;
const double eps = 1e-6;
int n, k;
int a[N];
double b[N];

bool check(double mid) {
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i] - mid;
	}
	double res = -1, mnv = 1e9;
	for (int i = k; i <= n; i++) {
		mnv = std::min(mnv, b[i - k]);
		res = std::max(res, b[i] - mnv);
	}
	return res >= 0;
}

bool chk1(double mid){
    std::stack<int> s;
    for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i] - mid;
	}
    int minPrefix=0;
    for(int i=1;i<=n;i++){
        while(!s.empty()&&b[i]-b[s.top()]>=0){
            int j=s.top();
            s.pop();
            if(i-j>=k) return true;
        }
        s.push(i);
    }
    return false;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	double l = 1, r = 1e6;
	while (l + eps < r) {
		double mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%.6lf\n", l);
	return 0;
}