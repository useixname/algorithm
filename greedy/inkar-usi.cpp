#include<bits/stdc++.h>
using namespace std;
char c[1005][1005], mx, ch;
int n, m, dx[]={0, 0, -1, 1}, dy[]={1, -1, 0, 0};
int main () {
	cin >> n >> m;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=m; j++) 
			cin >> c[i][j],
			mx=max(mx, c[i][j]);
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=m; j++) 
			if (c[i][j]==mx) 
				for (int k=0; k<4; k++) {
					int x=i+dx[k], y=j+dy[k];
					if (x>=1&&x<=n&&y>=1&&y<=m&&c[x][y]!='#') 
						ch=max(ch, c[x][y]);
				}
	if (mx!=ch)
		cout << mx;
	cout << ch;
	return 0;
}