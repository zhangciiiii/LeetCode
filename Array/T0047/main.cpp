//
//  main.cpp
//  LeetCodeTest
//
//  Created by ZhangChi on 2020/12/28.
//

#include <iostream>
#include<vector>
#include<stack>
#include<map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> vResult;
        sort(nums.begin(), nums.end());
        Backtrack(vResult, nums, 0);
        return vResult;
    }


    void Backtrack(vector<vector<int>> &vResult, vector<int> &nums, int nCurrentIndex)
    {
        if (nCurrentIndex == nums.size())
            vResult.push_back(nums);
        for (int i = nCurrentIndex; i < nums.size(); ++i)
        {
            sort(nums.begin() + nCurrentIndex, nums.end());
            if(i == nCurrentIndex || ( (i > nCurrentIndex)&&(nums[i-1] != nums[i])) )
            {
                swap(nums[i], nums[nCurrentIndex]);
                Backtrack(vResult, nums, nCurrentIndex + 1);
                swap(nums[i], nums[nCurrentIndex]);
            }


        }
    }	
    
};

