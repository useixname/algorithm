#include<bits/stdc++.h>
using namespace std;
const int N=256;
char s[N];
int a,b,c;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1;
    for(int i=1;i<=strlen(s+1);i++){
        if(s[i]=='a'){
            i+=3;
            if(s[i]=='b'){
                a=b;
            }
            else if(s[i]=='c'){
                a=c;
            }
            else if(s[i]=='a'){
                a=a;
            }
            else{
                a=s[i]-'0';
            }
        }
        else if(s[i]=='b'){
            i+=3;
            if(s[i]=='b'){
                b=b;
            }
            else if(s[i]=='c'){
                b=c;
            }
            else if(s[i]=='a'){
                b=a;
            }
            else{
                b=s[i]-'0';
            }
        }
        else if(s[i]=='c'){
            i+=3;
            if(s[i]=='b'){
                c=b;
            }
            else if(s[i]=='c'){
                c=c;
            }
            else if(s[i]=='a'){
                c=a;
            }
            else{
                c=s[i]-'0';
            }
        }
        else{
            continue;
        }
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}