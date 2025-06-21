#include<cstdio>
#include<algorithm>
using namespace std;
int n,minn=101,maxn;
double avg;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        minn=min(x,minn);
        maxn=max(x,maxn);
        avg+=x;
    }
    printf("%d\n%d\n%.2f",maxn,minn,avg/n);
    return 0;
}