#include<bits/stdc++.h>
using namespace std;
char s1[7],s2[7];
int sum1=1,sum2=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s1+1>>s2+1;
    int l1=strlen(s1+1);
    int l2=strlen(s2+1);
    for(int i=1;i<=l1;i++){
        sum1*=(s1[i]-'A'+1);
    }
    for(int i=1;i<=l2;i++){
        sum2*=(s2[i]-'A'+1);
    }
    if(sum1%47==sum2%47){
        cout<<"GO";
    }
    else{
        cout<<"STAY";
    }
    return 0;
}