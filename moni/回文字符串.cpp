#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int get_len_front(){
	int sum=0;
	for(int i=0;i<len;i++){
		if(s[i]=='l'||s[i]=='q'||s[i]=='b') sum++;
		else break;
	}
	return sum;
}//获取len1
int get_len_back(){
	int sum=0;
	for(int i=len-1;i>=0;i--){
		if(s[i]=='l'||s[i]=='q'||s[i]=='b') sum++;
		else break;
	}
	return sum;
}//获取len2
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		len=s.length();
		int len1=get_len_front();
		int len2=get_len_back();
		if(len1==len2&&len1==len){
			cout<<"Yes\n";
			continue;
		}//若整个字符串都为特殊字符，那么将原串倒序拼在前面即可，所以答案为Yes
		int bj=1;
		if(len1<=len2){
            // len-(len2-len1)-1;
			for(int i=0;i<len-len2+len1-1;i++){
				if(s[i]!=s[len-len2+len1-1-i]){
					cout<<"No\n";bj=0;break;
				}//判断是否回文
			}
			if(bj) cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
    //qqmkllq
    return 0;
}