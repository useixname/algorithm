#include<bits/stdc++.h>
using namespace std;
int net[4][2]={{0,-1},{0,1},{-1,0},{1,0}};//ÉÏÏÂ×óÓÒ
int t,x,y,sx,sy,f;

int main(){
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        string now="0";
        for(int i=0;i<n;i++){
            if(s[i]>='0'&&s[i]<='9'){
                now+=s[i];
            }
            else{
                int d=stoi(now);
                x+=net[f][0]*d;
                y+=net[f][1]*d;
                if(s[i]=='L'){
                    if(f==0){
                        f=2;
                    }
                    else if(f==1){
                        f=3;
                    }
                    else if(f==2){
                        f=1;
                    }
                    else{
                        f=0;
                    }
                }
                else if(s[i]=='R'){
                    if(f==0){
                        f=3;
                    }
                    else if(f==1){
                        f=2;
                    }
                    else if(f==2){
                        f=0;
                    }
                    else{
                        f=1;
                    }
                }
                now="0";
            }
        }
        int d=stoi(now);
        x+=net[f][0]*d;
        y+=net[f][1]*d;
        double d1=sqrt((x-sx)*(x-sx)+(y-sy)*(y-sy));
        printf("%.2f\n",d1);
        sx=x;
        sy=y;
    }
    return 0;
}