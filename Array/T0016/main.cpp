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
    int threeSumClosest(vector<int>& nums, int target) {
        int left=0;
        int right = int(nums.size()-1);
        int result = INT_MAX;
        int current_sum = 0;
        
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size()-1; ){
            left = i+1;
            right = int(nums.size()-1);
            while(left < right){
                current_sum = nums[i] + nums[left] + nums[right];
                result =  abs(current_sum-target)>abs(result-target)? result:current_sum;
                if (current_sum == target){
                    return current_sum;
                }
                
                else if (current_sum < target){
                    while (left < right && nums[left]==nums[left+1]) {
                        ++left;
                    }
                    ++left;
                }
                
                else{
                    while (left < right && nums[right]==nums[right-1]) {
                        --right;
                    }
                    --right;
                }
            }
            
            while(i < int(nums.size()-1) && nums[i]==nums[i+1]){
                ++i;
            }
            ++i;
        }
        return result;
    }
};

int main() {
    // insert code here...
    Solution T;
    vector<int> nums={1,1,1,1};
    cout<<0<<endl;
    int x = T.threeSumClosest(nums, 100);
    cout<<x<<endl;
    return 0;
}
