#include<iostream>
using namespace std;
int n,x,mins=1000010,maxs=-1;
int a[1000010];
int main()
{
    cin>>n;
    while(cin>>x)
    {
        mins=min(mins,x);
        maxs=max(maxs,x);
        a[x]++;
    }
    int t;
    for(int i=mins;i<=maxs;i++)
    {
        if(a[i]==0) t=i;
        if(a[i]>1){cout<<t<<" "<<i;return 0;}
    }
    return 0;
}