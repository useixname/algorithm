#include<bits/stdc++.h>
using namespace std;

const int N=1000;
int a[N], b[N];        // a 存储当前累加总和，b 存储当前单次迭代乘2减1的值
int n, la, lb;         // n 为迭代次数，la 和 lb 分别是数组 a 和 b 的长度（有效位数）
string s;              // 输入的大整数目标值，用字符串存储

// b = b * 2 - 1，使用高精度实现
void mul(){
    // b数组每一位都乘以2
    for(int i=1;i<=lb;i++){
        b[i] *= 2;
    }
    // 处理进位
    for(int i=1;i<=lb;i++){
        b[i+1] += b[i] / 10;
        b[i] %= 10;
    }
    // 如果最高位产生进位，扩展 lb
    if(b[lb+1]) lb++;

    // 将结果减1，b = b - 1
    int k = 1;
    while(b[k] == 0){   // 向高位借位
        b[k] = 9;
        k++;
    }
    b[k]--;             // 执行减1

    // 去除高位前导 0
    while(b[lb] == 0){
        lb--;
    }
}

// 累加 a += b，使用高精度加法
void add(){
    la = max(la, lb);
    for(int i=1;i<=la;i++){
        a[i] += b[i];            // 对应位相加
        a[i+1] += a[i] / 10;     // 处理进位
        a[i] %= 10;
    }
    if(a[la+1]) la++;            // 如果有进位，更新长度
}

// 比较当前计算结果与目标值 s 的大小
// 返回 1 表示 a > s，2 表示 a < s，3 表示 a == s
int chk(string s1){
    memset(a, 0, sizeof(a));    // 清空数组 a
    memset(b, 0, sizeof(b));    // 清空数组 b

    int l = s1.size();
    la = lb = l;

    // 将字符串 s1 反转填入高精度数组 a 和 b（低位在前）
    for(int i=l-1;i>=0;i--){
        a[l-i] = s1[i] - '0';
        b[l-i] = s1[i] - '0';
    }

    // 执行 n 次迭代：每次 b = b * 2 - 1，然后加到 a 上
    for(int i=1;i<=n;i++){
        mul();
        add();
    }

    // 将 a 与输入的大整数字符串 s 进行比较
    int l1 = s.size();
    if(la > l1) return 1;        // 长度大，说明大于
    else if(la < l1) return 2;   // 长度小，说明小于

    // 长度相等，从高位开始逐位比较
    for(int i=1;i<=la;i++){
        if(a[la - i + 1] > (s[i - 1] - '0')) return 1;
        else if(a[la - i + 1] < (s[i - 1] - '0')) return 2;
    }

    return 3;  // 完全相等
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> s;

    // 二分查找答案，查找最小的起始值 x，使得 x + (2x-1) + (4x-3) + ... 的结果 == s
    int l = 1, r = 100;
    while(l <= r){
        int mid = l + r >> 1;
        string s1 = to_string(mid);  // 将当前中间值转为字符串
        int k = chk(s1);            // 检查当前起始值是否可行

        if(k == 1){        // 当前结果过大，减小起始值
            r = mid - 1;
        }
        else if(k == 2){   // 当前结果过小，增大起始值
            l = mid + 1;
        }
        else{              // 正好相等，输出答案
            cout << mid;
            return 0;
        }
    }

    return 0;
}
