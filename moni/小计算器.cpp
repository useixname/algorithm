#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// 将单个字符转换为它的数值（'0'–'9' → 0–9, 'A'–'Z' → 10–35）
int char2val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

// 将一个用字符串 s 表示的 base 进制数转换为十进制
// 假设结果不超过 2^63?1
int64 toDecimal(const string &s, int base) {
    int64 r = 0;
    for (char c : s) {
        r = r * base + char2val(c);
    }
    return r;
}

// 将十进制数 x 转换为 base 进制的字符串表示
string fromDecimal(int64 x, int base) {
    if (x == 0) return "0";
    string s;
    while (x > 0) {
        int d = x % base;
        if (d < 10) s.push_back('0' + d);
        else         s.push_back('A' + (d - 10));
        x /= base;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    int64 reg = 0;        // 寄存器当前保存的十进制值
    int  base = 10;       // 当前进制
    string  op;           // 当前读到的指令
    // pendingOp 如果非空，表示读到了 ADD/SUB/...，等待下一个 NUM 来执行
    string pendingOp;     

    while (M--) {
        cin >> op;
        if (op == "NUM") {
            string s;
            cin >> s;
            int64 v = toDecimal(s, base);
            if (pendingOp.empty()) {
                // 没有挂起运算，直接当做赋值
                reg = v;
            } else {
                // 有挂起运算，执行后清空 pendingOp
                if (pendingOp == "ADD") reg += v;
                else if (pendingOp == "SUB") reg -= v;
                else if (pendingOp == "MUL") reg *= v;
                else if (pendingOp == "DIV") if (v) reg /= v;
                else if (pendingOp == "MOD") if (v) reg %= v;
                pendingOp.clear();
            }
        }
        else if (op == "ADD" || op == "SUB" || op == "MUL" 
              || op == "DIV" || op == "MOD") {
            // 记录下一个 NUM 要执行的运算
            pendingOp = op;
        }
        else if (op == "CHANGE") {
            // 直接切换进制，不影響 reg 的值
            cin >> base;
        }
        else if (op == "EQUAL") {
            // 将当前 reg 用当前 base 输出
            cout << fromDecimal(reg, base) << "\n";
        }
        else if (op == "CLEAR") {
            // 清零并清除挂起运算
            reg = 0;
            pendingOp.clear();
        }
        // 其他情况不可能出现
    }

    return 0;
}
