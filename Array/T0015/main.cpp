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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left=0;
        int right = int(nums.size()-1);
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size(); ){
            left = i+1;
            right = int(nums.size()-1);
            while(left < right){
                if (nums[i] + nums[left] + nums[right] == 0){
                    vector<int> tmp={nums[i], nums[left], nums[right]};
                    result.push_back(tmp);
                    while (left < right && nums[left]==nums[left+1]) {
                        ++left;
                    }
                    ++left;
                }
                
                else if (nums[i] + nums[left] + nums[right] < 0){
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
    cout<< "Hello, World!\n";
    return 0;
}
