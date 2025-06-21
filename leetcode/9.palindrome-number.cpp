/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        int a[30];
        int k=1;
        if(x<0) return false;
        else{
            while(x>0){
                a[k++]=x%10;
                x/=10;
            }
        }
        k--;
        int m=k/2;
        for(int i=1;i<=m;i++){
            if(a[i]!=a[k-i+1]) return false;
        }
        return true;
    }
};
// @lc code=end
