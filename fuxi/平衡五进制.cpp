#include<bits/stdc++.h>
using namespace std;
int a[6]={1,5,25,125,625};
vector<int>digits;
int n;

void balance(int n){
    while(n!=0){
        int r=n%5,d;
        if(r<=2){
            d=r;
            n=(n-d)/5;
        }
        else if(r==3){
            d=-2;
            n=(n-d)/5;
        }
        else{
            d=-1;
            n=(n-d)/5;
        }
        digits.push_back(d);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    balance(n);
    int l=digits.size()-1;
    for(int i=l;i>=0;i--){
        if(digits[i]==0) continue;
        if(i==l) cout<<digits[i]<<"*"<<a[i];
        else{
            if(digits[i]>0){
                if(digits[i]!=1) cout<<"+"<<digits[i]<<"*"<<a[i];
                else cout<<"+"<<a[i];
            }
            else cout<<digits[i]<<"*"<<a[i];
        }
    }
    return 0;
}