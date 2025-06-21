#include<bits/stdc++.h>
using namespace std;
int a,b,x,y;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>b>>x>>y;
    if(a>b){
        swap(a,b);
    }
    if(x>y){
        swap(x,y);
    }
    int ans=b-a;
    if(y<=a){
        cout<<ans;
    }
    else{
        int d=abs(a-x)+abs(b-y);
        if(d<ans){
            cout<<d;
        }
        else{
            cout<<ans;
        }
    }
    return 0;
}