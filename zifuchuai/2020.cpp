#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int cnt = 0;
		string str;
		cin >> str;
		for (int i = 0; i <= n - 4;) {
			if (str[i] == '2' && str[i + 1] == '0' && str[i + 2] == '2' && str[i + 3] == '0') {
				cnt++;
				i += 4;
			}
			else {
				i++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}