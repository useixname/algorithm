#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+10;
int ans=-233333333,n,m,a,sum[maxn];
deque<int>q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        sum[i]=sum[i-1]+a;//前缀和
    }
    q.push_back(0);//赋初值
    //求sum[j]最小的区间(j>=i-m&&j<=i-1)
    for(int i=1;i<=n;i++)
    {
        while(q.front()+m<i)
            q.pop_front();//越界就pop
        ans=fmax(ans,sum[i]-sum[q.front()]);
        while(!q.empty()&&sum[q.back()]>=sum[i])//递减就pop
            q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",ans);
    return 0;
}
