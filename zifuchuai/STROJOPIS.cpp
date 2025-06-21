#include<bits/stdc++.h>
using namespace std;
const int N=55;
char s[N];
int ans[9];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='1'||s[i]=='Q'||s[i]=='A'||s[i]=='Z'){
            ans[1]++;
        }
        else if(s[i]=='2'||s[i]=='W'||s[i]=='S'||s[i]=='X'){
            ans[2]++;
        }
        else if(s[i]=='3'||s[i]=='E'||s[i]=='D'||s[i]=='C'){
            ans[3]++;
        }
        else if(s[i]=='4'||s[i]=='R'||s[i]=='F'||s[i]=='V'||s[i]=='5'||s[i]=='T'||s[i]=='G'||s[i]=='B'){
            ans[4]++;
        }
        else if(s[i]=='6'||s[i]=='Y'||s[i]=='H'||s[i]=='N'||s[i]=='7'||s[i]=='U'||s[i]=='J'||s[i]=='M'){
            ans[5]++;
        }
        else if(s[i]=='8'||s[i]=='I'||s[i]=='K'||s[i]==','){
            ans[6]++;
        }
        else if(s[i]=='9'||s[i]=='O'||s[i]=='L'||s[i]=='.'){
            ans[7]++;
        }
        else if(s[i]=='0'||s[i]=='P'||s[i]==';'||s[i]=='/'||s[i]=='-'||s[i]=='='||s[i]=='['||s[i]==']'||s[i]=='\''){
            ans[8]++;
        }
    }
    for(int i=1;i<=8;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}