#include<bits/stdc++.h>
using namespace std;
<<<<<<< HEAD:math/è´¨å› æ•°åˆ†è§£.cpp
<<<<<<< HEAD:math/è´¨å› æ•°åˆ†è§£.cpp
#define int long long  // Ê¹ÓÃ long long ÀàĞÍ´¦Àí´óÊı
int n;

// Çó×î´óÖÊÒòÊıµÄº¯Êı
int decompose(int x) {
    int ans = 0;  // ³õÊ¼»¯´ğ°¸Îª0
    // ´Ó 2 µ½ sqrt(x) ±éÀúËùÓĞ¿ÉÄÜµÄÒòÊı
    for (int i = 2; i * i <= x; i++) {
        // µ± x ¿ÉÒÔ±» i Õû³ıÊ±
        while (x % i == 0) {
            ans = i;  // ¸üĞÂ×î´óÖÊÒòÊı
            x /= i;  // ½« x ³ıÒÔ i£¬¼ÌĞø·Ö½â
        }
    }
    // Èç¹û x ÈÔ´óÓÚ 1£¬ËµÃ÷ x ±¾ÉíÊÇÒ»¸öÖÊÊı
    if (x > 1) {
        ans = max(x, ans);  // ¸üĞÂ×î´óÖÊÒòÊı
    }
    return ans;  // ·µ»Ø×î´óÖÊÒòÊı
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin >> n;  // ÊäÈëÕûÊı n
    cout << decompose(n);  // Êä³ö n µÄ×î´óÖÊÒòÊı
    return 0;
}
=======
=======
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e:shulun/è´¨å› æ•°åˆ†è§£.cpp
#define int long long
int n;


int decompose(int x){
    int ans;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            ans=i;
            x/=i;
        }
    }
    if(x>1){
        ans=max(x,ans);
    };
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    cout<<decompose(n);
    return 0;
<<<<<<< HEAD:math/è´¨å› æ•°åˆ†è§£.cpp
}
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e:shulun/è´¨å› æ•°åˆ†è§£.cpp
=======
}
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e:shulun/è´¨å› æ•°åˆ†è§£.cpp
