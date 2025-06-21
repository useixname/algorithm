#include<bits/stdc++.h>
using namespace std;
int n,k,cntl,cntr;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>k;
    if(k<0){
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            if(x>0&&x<abs(k)) cntl++;
            if(x<0&&abs(x)>abs(k)) cntr++;
        }
    }
    else{
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            if(x<0&&abs(x)>k) cntr++;
            if(x>0&&x<k) cntl++;
        }
    }
    if(cntr==0||cntl==0){
        cout<<1;
        return 0;
    }
    cout<<cntl+cntr+1;
    return 0;
}