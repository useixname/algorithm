#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000005];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, ans = 0,maxn=0,l=1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            maxn=max(maxn,a[i]);
            if(maxn==i){
                ans+=(i-l+1!=1)*(i-l+1);
                l=i+1;
            }
        }
        // int i = 1;
        // while (i <= n)
        // {
        //     if (a[i] == i)
        //         i++;
        //     else
        //     {
        //         int maxv = a[i];
        //         int j = i + 1;
        //         maxv = max(maxv, a[j]);
        //         while (maxv > j)
        //         {
        //             j++;
        //             maxv = max(maxv, a[j]);
        //         }
        //         ans += j - i + 1;
        //         i = j + 1;
        //     }
        // }
        cout << ans << '\n';
    }
    return 0;
}