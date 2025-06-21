/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int k=0;
        string ret="";
        while(1){
            if(n<=1) return strs[0];
            for(int i=0;i<n;i++){
                if(strs[i].size()==0) return "";
                if(k>=strs[i].size()) return ret;
            }
            char c=strs[0][k];
            for(int i=1;i<n;i++){
                if(strs[i][k]!=c){
                    return ret;
                }
            }
            ret+=c;
            k++;
        }
        return ret;
    }
};
// @lc code=end

