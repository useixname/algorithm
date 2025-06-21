/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ret=0;
        while(x){
            if(ret<INT_MIN /10||ret>INT_MAX / 10){
                return 0;
            }
            int d=x%10;
            x/=10;
            ret=ret*10+d;
        }
        return ret;
    }
};
// @lc code=end

