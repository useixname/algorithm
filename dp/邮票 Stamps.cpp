#include<bits/stdc++.h>
using namespace std;
int k,n,i,j,s,a;
int f[2000000];
int main() 
{
    scanf("%d%d",&k,&n);
    for (i=1;i<=2000000;i++) f[i]=2333;
    f[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for (j=a;j<=2000000;j++)
        if (f[j-a]+1<=k)
            f[j]=min(f[j],f[j-a]+1);
    } 
    s=0;
    for (i=1;i<=2000000;i++)
        if (f[i]==2333)
        {
            s=i-1;
            break;
        }
    printf("%d\n",s);
    return 0;
}