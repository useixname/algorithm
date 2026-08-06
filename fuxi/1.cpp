#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int k=a[i];
        for(int j=i+1;i<=n;j++){
            if(a[j]<k) k=a[j];
        }
        a[i]=k;
        printf("%d ",a[i]);
    }
    return 0;
}