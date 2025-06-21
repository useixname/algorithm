#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void aftord(string inord,string front){
    if (inord.size()>0){
        char ch=front[0];
        int k=inord.find(ch);
        aftord(inord.substr(0,k),front.substr(1,k));
        aftord(inord.substr(k+1),front.substr(k+1));
        cout<<ch;
    }
}
int main(){
    string inord,front;
    cin>>inord;cin>>front;
    aftord(inord,front);cout<<endl;
    return 0;
}