#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int x,flag=1,s=0,r=0,c=0;
    while(cin>>x){
        int r0=r,c0=c;
        s+=x;
        r=s/n,c=s%n;
        if(flag){
            for(int i=r0;i<=r;i++){
                if(i==r0&&r0==r){
                    for(int j=c0;j<c;j++){
                        cout<<0;
                    }
                }
                else if(i==r0&&r0!=r){
                    for(int j=c0;j<n;j++){
                        cout<<0;
                    }
                    cout<<'\n';
                }
                else if(i==r){
                    for(int j=0;j<c;j++){
                        cout<<0;
                    }
                }
                else{
                    for(int j=0;j<n;j++){
                        cout<<0;
                    }
                    cout<<'\n';
                }
            }
        }
        else{
            for(int i=r0;i<=r;i++){
                if(i==r0&&r0==r){
                    for(int j=c0;j<c;j++){
                        cout<<1;
                    }
                }
                else if(i==r0&&r0!=r){
                    for(int j=c0;j<n;j++){
                        cout<<1;
                    }
                    cout<<'\n';
                }
                else if(i==r){
                    for(int j=0;j<c;j++){
                        cout<<1;
                    }
                }
                else{
                    for(int j=0;j<n;j++){
                        cout<<1;
                    }
                    cout<<'\n';
                }
            }
        }
        flag=!flag;
    }
    return 0;
}