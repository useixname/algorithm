#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int ans;
int a[51];
int f[51][1001];
int main()
{
    scanf("%d%d%d",&n,&l,&r);
    f[0][l]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
        for(int j=r;j>=0;j--)
        {
            if(j-a[i]>=0)
                f[i][j]=f[i][j]||f[i-1][j-a[i]];
            if(j+a[i]<=r)
                f[i][j]=f[i][j]||f[i-1][j+a[i]];
        }
    for(int i=r;i>=1;i--)
        if(f[n][i]==1)
        {
            printf("%d",i);
            return 0;
        }
    printf("-1");
    return 0;
}