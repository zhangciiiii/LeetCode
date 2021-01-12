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
    int maxSubArray(vector<int>& nums) {
        int MaxSub = nums[0];
        int CurrentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            CurrentSum = max(nums[i] + CurrentSum, nums[i] );
            MaxSub = max(MaxSub,CurrentSum);
            //cout<<CurrentSum<<endl;
        }
        
        return MaxSub;
    }
};

int main() {
    // insert code here...
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    sol.maxSubArray(nums);
    return 0;
}
