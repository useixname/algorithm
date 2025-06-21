#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int f[N][N]={0};

int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a);
        for(int j=1;j<=a;++j)
        {
            f[i][j]=INT_MAX-1000;
            int b,c;
            scanf("%d",&b);
            while(b!=0)
            {
                scanf("%d",&c);
                f[i][j]=min(f[i-1][b]+c,f[i][j]);
                scanf("%d",&b);
            }
        }
    }
    int min=INT_MAX;
    for(int i=1;i<=a;++i)
        min=f[n][i]<min?f[n][i]:min;
    printf("%d",min);
    return 0;
}