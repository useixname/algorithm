#include<bits/stdc++.h>
using namespace std;
int n;
string a,c;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>a>>c;
    for(int i=0;i<n;i++){
        if(a[i]=='a'){
            if(c[i]!='a'){
                cout<<-1;
                return 0;
            }
        }
        else{
            if(c[i]>a[i]){
                cout<<-1;
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='a'){
            if(c[i]=='a'){
                cout<<c[i];
            }
            else if(c[i]!='a'){
                cout<<char ('a'+1);
            }
        }
        else if(a[i]=='z'){
            if(c[i]=='z'){
                cout<<c[i];
            }
            else if(c[i]!='z'){
                cout<<c[i];
            }
        }
        else{
            if(c[i]==a[i]){
                cout<<char (a[i]+1);
            }
            else if(c[i]<a[i]){
                cout<<c[i];
            }
        }
    }
    return 0;
}