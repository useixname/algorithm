#include<bits/stdc++.h>
using namespace std;
int num[15],ans;
int main(){
    for(int i=1;i<=100000000;i++){
        memset(num,0,sizeof(num));
        int x=i,cnt=0;
        while(x){
            num[cnt++]=x%10;
            x/=10;
        }
        if(cnt%2==0){
            int s1=0,s2=0;
            for(int i=0;i<cnt;i++){
                if(i<cnt/2) s1+=num[i];
                else s2+=num[i];
            }
            if(s1==s2) ans++;
        }
    }
    cout<<ans;
    return 0;
}

