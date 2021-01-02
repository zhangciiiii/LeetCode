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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> Result;
        auto num_size = nums.size();
        int left,right;
        int current2sum;
        int current4sum;
        
        sort(nums.begin(),nums.end());
        if (num_size<4)
            return Result;
        for (int i=0; i<=num_size-4;){
            for (int j=i+1;j<=num_size-3;){
                left = j+1;
                right = int(num_size-1);
                current2sum = nums[i]+nums[j];
                
                while(left<right){
                    current4sum = current2sum + nums[left] + nums[right];
                    if(current4sum == target){
                        Result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        
                        while(left<right && nums[left]==nums[left+1])
                            ++left;
                        ++left;
                    }
                    else if(current4sum > target){
                        while(left<right && nums[right]==nums[right-1])
                            --right;
                        --right;
                    }
                    else {
                        while(left<right && nums[left]==nums[left+1])
                            ++left;
                        ++left;
                    }
                }
                
                while(j<=num_size-4 && nums[j]==nums[j+1])
                    ++j;
                ++j;
            }
            
            while(i<=num_size-4 && nums[i]==nums[i+1])
                ++i;
            ++i;
        }
        return Result;
    }
};

int main() {
    // insert code here...

    return 0;
}
