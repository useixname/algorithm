#include <iostream>
using namespace std;

int main(){
    long long n, k, x;
    cin >> n >> k >> x;
    long long d = n - x; // 剩余差值
    // 如果 d mod (k+1) 不为 0，则先手必胜
    if(d % (k + 1) != 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
