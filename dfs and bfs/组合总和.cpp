#include<bits/stdc++.h>
using namespace std;

vector<int>& candidates;
int n,target;

class Solution {
public:
    vector<vector<int>> result; // 存储最终结果
    vector<int> combination; // 存储当前组合

    void backtrack(vector<int>& candidates, int target, int start) {
        // 如果目标值为0，保存当前组合
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        // 遍历从当前索引开始的候选数字
        for (int i = start; i < candidates.size(); i++) {
            if (target < candidates[i]) continue; // 剪枝，跳过无效选择
            combination.push_back(candidates[i]); // 选择当前数字
            backtrack(candidates, target - candidates[i], i); // 继续选择（可重复使用）
            combination.pop_back(); // 回溯，撤销选择
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 排序以便剪枝
        backtrack(candidates, target, 0); // 开始回溯
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>target;
    for(int i=0;i<n;i++){
        cin>>candidates[i];
    }
    Solution s;
    s.combinationSum(candidates,target);
    return 0;
}