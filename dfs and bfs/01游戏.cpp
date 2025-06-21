#include<bits/stdc++.h>
using namespace std;

// 定义一个全局字符数组 a，用于存储 n×n 的矩阵（题目中的棋盘或走廊）
// 数组下标均采用 1-indexed，下标范围为 [1, n]。
char a[15][15];

// n 表示矩阵的大小（n×n），题目要求 n≤15。
int n;

// 全局数组 rowZero 和 colZero 分别记录每一行和每一列中 '0' 的个数。
// 用于在 DFS 搜索过程中进行剪枝判断，确保每行和每列 '0' 的数量不超过 n/2。
int rowZero[15], colZero[15];

int ans;  // 用于记录最终的答案（在本代码中 ans 未被直接使用，而是通过输出找到合法矩阵时直接退出程序）

// 函数 chk() 用于检查当前矩阵是否满足题目要求：
// 1. 每一行和每一列中 '0' 的个数必须恰好为 n/2。
// 2. 每一行和每一列中不得出现连续三个相同的数字（即连续三个 '0' 或连续三个 '1'）。
bool chk(){
    // 检查每一行
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(a[i][j] == '0') cnt++;
            // 对于非边界位置 j，从 2 到 n-1，检查连续三个元素是否相同
            if(j >= 2 && j <= n-1){
                if(a[i][j-1] == a[i][j] && a[i][j] == a[i][j+1])
                    return false;
            }
        }
        // 如果第 i 行中 '0' 的个数不等于 n/2，返回 false
        if(cnt != n/2) return false;
    }
    // 检查每一列
    for(int j = 1; j <= n; j++){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i][j] == '0') cnt++;
            // 对于非边界位置 i，从 2 到 n-1，检查连续三个元素是否相同
            if(i >= 2 && i <= n-1){
                if(a[i-1][j] == a[i][j] && a[i][j] == a[i+1][j])
                    return false;
            }
        }
        // 如果第 j 列中 '0' 的个数不等于 n/2，返回 false
        if(cnt != n/2) return false;
    }
    return true;
}
 
// DFS 函数用于递归地填充矩阵中所有空白位置（用 '_' 表示）
// 参数说明：
//   row：当前正在填充的行号
//   col：当前正在填充的列号
//   rowZero：指向全局数组 rowZero 的指针，记录各行 '0' 的个数
//   colZero：指向全局数组 colZero 的指针，记录各列 '0' 的个数
void dfs(int row, int col, int *rowZero, int *colZero){
    if(row==n&&col>1){
      if(colZero[col-1]!=n/2) return;
    }
    // 如果当前列号超过 n，则进入下一行，并重置列号为 1
    if(col > n){ 
        if(rowZero[row]!=n/2) return;
        else dfs(row + 1, 1, rowZero, colZero); 
        return;
    }
    // 如果行号超过 n，则说明整个矩阵都已填满，
    // 调用 chk() 检查矩阵是否满足条件，如果满足，则输出矩阵并结束程序
    if(row > n){
        if(chk()){
            // 输出整个矩阵，每行输出一行
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    cout << a[i][j];
                }
                cout << '\n';
            }
            exit(0);  // 找到一种满足要求的方案后直接退出程序
        }
        return;
    }
    // 局部剪枝：检查当前填入位置可能引起的连续三个相同的情况
    // 如果当前列大于等于 3，检查同一行当前列及前两列是否形成连续三个相同的字符
    if(col >= 3){
        if(a[row][col] == a[row][col-1] && a[row][col] == a[row][col-2]){
            return;
        }
    }
    // 同理，如果当前行大于等于 3，检查同一列当前行及前两行是否形成连续三个相同的字符
    if(row >= 3){
        if(a[row][col] == a[row-1][col] && a[row][col] == a[row-2][col]){
            return;
        }
    }
    // 如果当前行已填 '0' 的个数超过 n/2 或当前列已填 '0' 的个数超过 n/2，则剪枝
    if(rowZero[row] > n/2 || colZero[col] > n/2) return;
    
    // 如果当前格子为空（标记为 '_'）
    if(a[row][col] == '_'){
        // 尝试填 '0'
        a[row][col] = '0';
        rowZero[row]++;   // 更新当前行 '0' 数量
        colZero[col]++;   // 更新当前列 '0' 数量
        dfs(row, col + 1, rowZero, colZero);
        rowZero[row]--;   // 回溯时恢复
        colZero[col]--;
        
        // 尝试填 '1'
        a[row][col] = '1';
        dfs(row, col + 1, rowZero, colZero);
        
        // 回溯：将当前格子恢复为空 '_'
        a[row][col] = '_';
    }
    else{
        // 如果当前位置已有值，则直接递归处理下一个位置
        dfs(row, col + 1, rowZero, colZero);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // 读入矩阵大小 n
    cin >> n;
    // 读入 n 行，每行一个字符串，存入矩阵 a，注意行号从 1 开始
    for(int i = 1; i <= n; i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    // 初始化 rowZero 数组：统计每行中 '0' 的个数（初始时根据输入已有的 '0'）
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == '0')
                rowZero[i]++;
        }
        // cout<<rowZero[i]<<'\n';
    }
    // 初始化 colZero 数组：统计每列中 '0' 的个数
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[j][i] == '0')
                colZero[i]++;
        }
        // cout<<colZero[i]<<'\n';
    }
    // 开始 DFS，从矩阵的左上角 (1,1) 开始填充
    dfs(1, 1, rowZero, colZero);
    return 0;
}
