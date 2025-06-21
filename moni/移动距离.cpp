#include<bits/stdc++.h>
using namespace std;
int w,n,m;
int x1,y11,x2,y2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>w>>n>>m;
    int maxn=max(n,m);
    int r=maxn/w+1;
    for(int i=1;i<=r;i++){
        if(i%2==0){
            for(int j=i*w,c=0;j>=(i-1)*w+1;j--,c++){
                if(j==n){
                    x1=i;
                    y11=c;
                }
                if(j==m){
                    x2=i;
                    y2=c;
                }
            }
        }
        else{
            for(int j=(i-1)*w+1,c=0;j<=i*w;j++,c++){
                if(j==n){
                    x1=i;
                    y11=c;
                }
                if(j==m){
                    x2=i;
                    y2=c;
                }
            }
        }
    }
    cout<<fabs(x1-x2)+fabs(y11-y2);
    return 0;
}