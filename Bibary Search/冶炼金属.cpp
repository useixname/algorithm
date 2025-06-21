#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int a,b;
}w[10010];

bool chk(int x){
    for(int i=1;i<=n;i++){
        if(w[i].a/x<w[i].b){
            return false;
        }
    }
    return true;
}

bool chk1(int x){
    for(int i=1;i<=n;i++){
        if(w[i].a/x>w[i].b){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i].a>>w[i].b;
    }
    int l1=1,r1=1e9+1;
    while(l1+1<r1){
        int mid=l1+r1>>1;
        if(chk1(mid)) r1=mid;
        else l1=mid;
    }
    int l2=1,r2=1e9+1;
    while(l2+1<r2){
        int mid=l2+r2>>1;
        if(chk(mid)) l2=mid;
        else r2=mid;
    }
    cout<<r1<<" "<<l2;
    return 0;
}