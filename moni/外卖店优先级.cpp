#include <iostream>
#include <algorithm>
using namespace std;
int n, m, t;
struct Node
{ // 创建结构体
    int ts;
    int id;
};
int ans = 0;               // 计算缓存中的外卖店铺数
Node arr[100005];          // 定义一个结构体数组
bool cmp(Node &x, Node &y) // sort函数的比较内容，即sort函数的第三个参数
{
    if (x.id != y.id)
        return x.id < y.id;
    else
        return x.ts < y.ts;
}
int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
        cin >> arr[i].ts >> arr[i].id;
    sort(arr + 1, arr + 1 + m, cmp); // 排序
    for (int i = 1; i <= m;)
    {
        int nowid = arr[i].id;       // 记录当前店铺的id
        int priority = 2;            // 我是从该店铺被发放订单的第二个时刻开始，因此优先级初值设为了2
        int flag = false;            // 标记是否让该店铺进入缓存
        while (arr[++i].id == nowid) // 直到下一家店铺不是当前店铺id为止，即当前店铺是否在t时刻仍在缓存中的一系列计算操作完成
        {
            if (arr[i].ts != arr[i - 1].ts)                            // 前后时刻不相等
                priority = priority - (arr[i].ts - arr[i - 1].ts - 1); // 因为"跳过"一个时间间隔为1个优先级，所以当前优先级要减去时间间隔,减1的意思是不含尾，因为尾部即此时有订单
            if (priority < 0)                                          // 优先级小于0，则归0
                priority = 0;
            if (priority <= 3) // 优先级小于3，则退出缓存
                flag = false;
            priority += 2; // 优先级+2后，再判断是否可以重新进入缓存中
            /*若该句写在前面，如果该店铺的优先级之前已经达到6，
            flag已经变为了true,但中间隔了4个时刻都没有订单，
            那么他的优先级就会变成2，加上2就会导致本来因该退出缓存却不行了*/
            if (priority >= 6) // 优先级大于6，则允许进入缓存
                flag = true;
        }
        if (flag) // 计算进入缓存的店铺的数目
        {
            if (t != arr[i - 1].ts)                        // 给定时刻t与当前店铺最后订单时刻不相等
                priority = priority - (t - arr[i - 1].ts); // 优先级减去时刻差
            if (priority > 3)                              // 优先级仍大于3，数量+1
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}