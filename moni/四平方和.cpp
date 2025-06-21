#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int n;

int main(){
    cin>>n;
    for(int a=0;a*a<=n;a++){
        for(int b=a;b*b+a*a<=n;b++){
            for(int c=b;c*c+b*b+a*a<=n;c++){
                for(int d=c;d*d+c*c+b*b+a*a<=n;d++){
                    int s=d*d+c*c+b*b+a*a;
                    if(s==n){
                        cout<<a<<" "<<b<<" "<<c<<" "<<d;
                        return 0;
                    }
                }
            }
        }
    }
}