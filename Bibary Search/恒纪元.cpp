#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e12+10;
//题目中保证了x,y,z不同时为1,所以我们可以枚举a,b,c来保存
//T(乱纪元)的值，这里我用STL中的set来保存T，set有去重的功能，并且可以自动升序排序，方便后续二分查找
int x,y,z,q; 
set<int> s;

signed main(){
    //cout<<(1LL*1<<40);//13位 
    cin>>x>>y>>z; 
    for(int i=0;i<=40;i++)
      for(int j=0;j<=40;j++)
        for(int k=0;k<=40;k++){
            int temp=1LL*(pow(x,i)+pow(y,j)+pow(z,k));
            if(temp<=1e13)
              s.insert(temp);
        }//求出了1e13以内的乱纪元 
    cin>>q;
    while(q--){
        int x,year=1; 
        cin>>x;//给出一个乱纪元 
        auto pos=s.find(x);//找到该乱纪元在set中的位置,返回一个迭代器 
        //找出下一个恒纪元 
        while(*(++pos)==x+1)//连续的数都为乱纪元 
           x++;
        //此时x位乱纪元，x的下一个位置位恒纪元，while在！=时停止循环 
        auto it=s.find(x); //找到该乱纪元 
        it++;//该乱纪元迭代器++即为下一个乱纪元的位置 
        cout<<x+1<<' '<<*it-(x+1)<<endl;
        //下一个乱纪元减去恒纪元即为恒纪元持续的年数 
    } 
}