/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastindex[256];
        memset(lastindex,-1,sizeof(lastindex));
        int start=0,max=0;
        for(int i=0;s[i]!='\0';i++){
            if(lastindex[s[i]]>=start){
                start=lastindex[s[i]]+1;
            }
            lastindex[s[i]]=i;
            max=fmax(i-start+1,max);
        }
        return max;
    }
};
// @lc code=end

//bacabcbb