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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> Result;
        vector<int> combine;
        int len = int(candidates.size());
        if (len == 0)
            return Result;
        sort(candidates.begin(),candidates.end());
        DFS(candidates, target, 0, len, combine, Result);
        return Result;
    }
    
    void DFS(vector<int>& candidates, int target, int begin, int len,
             vector<int>& combine, vector<vector<int>>& Result){
        if (target == 0){
            Result.emplace_back(combine);
            return;
        }
        if (target < 0)
            return;
        for (int i = begin; i < len; ++i){
            if (i==begin){
                combine.emplace_back(candidates[i]);
                DFS(candidates, target - candidates[i], i+1, len, combine, Result);
                combine.pop_back();
            }
            else if (candidates[i] != candidates[i-1]){
                combine.emplace_back(candidates[i]);
                DFS(candidates, target - candidates[i], i+1, len, combine, Result);
                combine.pop_back();
            }
            
        }
    }
};

int main() {
    // insert code here...
    vector<int> nums = {2,3,6,7};
    Solution sol;
    vector<vector<int>> Result = sol.combinationSum2(nums, 7);
    
    return 0;
}
