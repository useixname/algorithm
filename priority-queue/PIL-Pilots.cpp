#include<iostream>
#include<cstdio>
using namespace std;

#define ll long long
ll k, n, a[3000005], q_mx[3000005], q_mn[3000005];
ll head_mx, head_mn, tail_mx, tail_mn, len, pre;

int main(){
    // scanf input instead of freopen
    scanf("%lld%lld", &k, &n);
    if(n==1){cout<<1;return 0;}
    len = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    // 初始化队列
    q_mx[1] = 1; q_mn[1] = 1; pre = 1;
    head_mx = 1; tail_mx = 1; head_mn = 1; tail_mn = 1;

    for(int i = 2; i <= n; i++) {
        // 保持最大值队列递减
        while(head_mx <= tail_mx && a[q_mx[tail_mx]] < a[i]) {
            tail_mx--;
        }
        // 保持最小值队列递增
        while(head_mn <= tail_mn && a[q_mn[tail_mn]] > a[i]) {
            tail_mn--;
        }

        // 更新队列
        q_mx[++tail_mx] = i;
        q_mn[++tail_mn] = i;

        // 移动左边界pre，确保窗口内的最大最小值之差 <= k
        while(a[q_mx[head_mx]] - a[q_mn[head_mn]] > k) {
            if(q_mx[head_mx] < q_mn[head_mn]) {
                pre = q_mx[head_mx] + 1;//把当前最大值去掉
                head_mx++;//新的最大值
            } else {
                pre = q_mn[head_mn] + 1;
                head_mn++;
            }
        }

        // 更新当前窗口的最大长度
        len = max(len, i - pre + 1);
    }
    
    // 输出结果
    printf("%lld", len);
    return 0;
}
