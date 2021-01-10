//
//  main.cpp
//  LeetCodeTest
//
//  Created by ZhangChi on 2020/12/28.
//

#include <iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> Result;
        vector<int> combine;
        int len = int(candidates.size());
        if (len == 0)
            return Result;
        DFS(candidates, target, Result, combine, len, 0);
        return Result;
    }
    
    void DFS(vector<int>& candidates, int target, vector<vector<int>>& ans,
             vector<int>& combine, int len, int begin) {
        if (target == 0){
            ans.emplace_back(combine);
            return;
        }
            
        if (target < 0)
            return;
        
        for (int i = begin; i < len; ++i){
            combine.emplace_back(candidates[i]);
            DFS(candidates, target - candidates[i], ans, combine, len, i);
            combine.pop_back();
        }
    }
};

int main() {
    // insert code here...
    vector<int> nums = {2,3,6,7};
    Solution sol;
    vector<vector<int>> Result = sol.combinationSum(nums, 7);
    return 0;
}
