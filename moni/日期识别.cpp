#include<bits/stdc++.h>
using namespace std;
string s;

map<string,int> a={{"Jan",1},{"Feb",2},{"Mar",3},{"Apr",4},{"May",5},{"Jun",6},
                   {"Jul",7},{"Aug",8},{"Sep",9},{"Oct",10},{"Nov",11},{"Dec",12}};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    string m=s.substr(0,3);
    int d=(s[3]-'0')*10+(s[4]-'0');
    cout<<a[m]<<" "<<d;
    return 0;
}