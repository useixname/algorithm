#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int MAXN = 35; // 根据题目可能的范围，例如行数最多35
const int MAXM = 55; // 列数最多55

// 四个方向：下、左、右、上
int net[4][2] = { {1,0}, {0,-1}, {0,1}, {-1,0} };

char a[MAXN][MAXM];      // 存储地图信息，假设 1 表示障碍，其它值表示可通行（题目中具体含义请根据实际修改）
int vis[MAXN][MAXM];    // 访问标记

// 记录每个点的前驱信息以及用于到达该点的方向
struct Cell {
    int d;     // 到达该点时使用的方向编号（0: 下, 1: 左, 2: 右, 3: 上）
    int prex;  // 前驱点的行坐标
    int prey;  // 前驱点的列坐标
} preInfo[MAXN][MAXM];

int n, m;

// BFS搜索，寻找从 (1,1) 到 (n,m) 的路径
void bfs(){
    queue<PII> q;
    q.push({1, 1});
    vis[1][1] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int cx = cur.first, cy = cur.second;
        for (int i = 0; i < 4; i++){
            int tx = cx + net[i][0], ty = cy + net[i][1];
            // 检查边界条件，并假设 a[tx][ty] == 1 表示障碍，其他表示可通行
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] != '1' && !vis[tx][ty]){
                vis[tx][ty] = 1;
                preInfo[tx][ty].d = i;      // 保存方向 i（即从 (cx,cy) 到 (tx,ty) 的移动）
                preInfo[tx][ty].prex = cx;    // 保存前驱坐标
                preInfo[tx][ty].prey = cy;
                q.push({tx, ty});
                if(tx == n && ty == m) {
                    // 找到目的地 (n, m)，可以提前结束 BFS
                    return;
                }
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读入行数 n 和列数 m
    cin >> n >> m;
    // 读入地图数据
    // 假设输入的每个数字为 0 表示可通行，1 表示障碍
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
           cin>>a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
           cout<<a[i][j];
        }
        cout<<'\n';
    }
    // 进行 BFS 寻找路径
    bfs();
    
    // 现在从终点 (n, m) 反向回溯至起点 (1,1)
    string path;
    int x = n, y = m;
    while (!(x == 1 && y == 1)){
        int d = preInfo[x][y].d; // 记录从前驱到达 (x,y) 的方向
        // 由于我们是反向回溯，实际移动方向需要取反
        // 原方向编码： 0: 下, 1: 左, 2: 右, 3: 上
        // 反向移动：如果原来从前驱移动"下"到达当前，则反向为 "上"，依此类推。
        if(d == 0)       path.push_back('D'); // 反向为上
        else if(d == 1)  path.push_back('L'); // 反向为右
        else if(d == 2)  path.push_back('R'); // 反向为左
        else             path.push_back('U'); // d == 3，反向为下
        
        int px = preInfo[x][y].prex;
        int py = preInfo[x][y].prey;
        x = px;
        y = py;
    }
    
    // 因为我们是从终点反向回溯，所以最终需要将路径反转
    reverse(path.begin(), path.end());
    
    cout << path << "\n";
    return 0;
}

// "DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR"
