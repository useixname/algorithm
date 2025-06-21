<<<<<<< HEAD
<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

// 获取灵感加成
int get_inspiration_bonus(const string &s) {
    string prefix = "lanqiobe";
    int max_bonus = 0;
    for (int i = 1; i <= 8; i++) {
        if (s.find(prefix.substr(0, i)) == 0) { // 检查是否包含前缀
            max_bonus = i * 10;
        }
    }
    return max_bonus;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int max_infectivity = 0;
    string best_substring;

    // 遍历所有起始位置
    for (int i = 0; i < n; ++i) {
        unordered_set<char> char_set; // 用于判断字符唯一性
        int sum = 0;                 // 当前子串音高之和
        string current_substring;

        // 尝试扩展子串
        for (int j = i; j < n; ++j) {
            char c = s[j];
            if (char_set.count(c)) break; // 遇到重复字符，停止扩展

            char_set.insert(c);
            sum += c - 'a' + 1;
            current_substring += c;

            // 计算感染力
            int bonus = get_inspiration_bonus(current_substring);
            int infectivity = sum + bonus;

            // 更新最佳子串
            if (infectivity > max_infectivity || 
                (infectivity == max_infectivity && current_substring < best_substring)) {
                max_infectivity = infectivity;
                best_substring = current_substring;
            }
        }
    }

    cout << best_substring << endl;
    return 0;
}
=======
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e3+10;
int n;
char a[N][N];

int main(){
    memset(a,' ',sizeof(a));
    scanf("%d",&n);
    int k=n/2+1,t=0;
    for(int i=1;i<=k;i++){
        for(int j=k-t;j<=k+t;j++){
            a[i][j]='*';
        }
        t++;
    }
    t-=2;
    for(int i=k+1;i<=n;i++){
        for(int j=k-t;j<=k+t;j++){
            a[i][j]='*';
        }
        t--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
=======
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e3+10;
int n;
char a[N][N];

int main(){
    memset(a,' ',sizeof(a));
    scanf("%d",&n);
    int k=n/2+1,t=0;
    for(int i=1;i<=k;i++){
        for(int j=k-t;j<=k+t;j++){
            a[i][j]='*';
        }
        t++;
    }
    t-=2;
    for(int i=k+1;i<=n;i++){
        for(int j=k-t;j<=k+t;j++){
            a[i][j]='*';
        }
        t--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
