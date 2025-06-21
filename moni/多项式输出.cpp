#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int n;

void print(){
    for(int i=n;i>=0;i--){
        if(i==n){
            if(a[i]!=0){
                if(abs(a[i])!=1) cout<<a[i]<<"x^"<<i;
                else{
                    if(a[i]==1) cout<<"x^"<<i;
                    else{
                        cout<<"-x^"<<i;
                    }
                }
            }
        }
        else if(i>1){
            if(a[i]!=0){
                if(a[i]>0){
                    if(a[i]==1) cout<<"+"<<"x^"<<i;
                    else cout<<"+"<<a[i]<<"x^"<<i;
                }
                else{
                    if(a[i]==-1) cout<<"-"<<"x^"<<i;
                    else{
                        cout<<a[i]<<"x^"<<i;
                    }
                }
            }
        }
        else if(i==1){
            if(a[i]!=0){
                if(a[i]>0){
                    if(a[i]==1) cout<<"+"<<"x";
                    else cout<<"+"<<a[i]<<"x";
                }
                else{
                    if(a[i]==-1) cout<<"-"<<"x";
                    else{
                        cout<<a[i]<<"x";
                    }
                }
            }
        }
        else{
            if(a[i]!=0){
                if(a[i]>0) cout<<"+"<<a[i];
                else cout<<a[i];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=n;i>=0;i--){
        cin>>a[i];
    }
    if(n==0){
        cout<<a[0];
    }
    else{
        print();
    }
    return 0;
}