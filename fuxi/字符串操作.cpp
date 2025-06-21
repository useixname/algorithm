#include<bits/stdc++.h>
using namespace std;
string s;
int n;
/*
s.insert(int pos,string str);pos代表你要在字符串第pos个位置之前插入字符串str,下标从0开始
列如:s="motao" s.insert(5," is shuaige") s="motao is shuaige"
*/
/*
s.find(string str)返回的是第一个出现该字符串的起始位置,如果s.find(str)==string::npos就代表找不到str
同样,下标从0开始
*/
/*
s.erase(int pos,int size)
从下标为pos的位置开始删除长度为size的字符串
s="helloworld"
s.erase(5,5) s="hello"
*/
void soved(){
    int a,b;
    string s1,s2;
    cin>>a>>b>>s1>>s2;
    string t=s.substr(a-1,b-a+1);
    s=s.substr(0,a-1)+s.substr(b);
    cout<<s<<'\n';
    string s3=s1+s2;
    int index1=s.find(s3);
    if(index1==string::npos){
        s+=t;
    }
    else{
        cout<<index1<<'\n';
        s.insert(index1+s1.size(),t);
    }
    cout<<s<<'\n';
}

int main(){
    cin>>s;
    cin>>n;
    while(n--){
        soved();
    }
    cout<<s;
    return 0;
}