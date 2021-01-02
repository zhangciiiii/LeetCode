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
    void nextPermutation(vector<int>& nums) {
        int i =int(nums.size()-1);
        for (; i>=0;--i){
            if (i==0)
                return;;
            if (i==1 && nums[i-1]>nums[i]){
                reverse(nums.begin(), nums.end());
                return;
            }
            if (nums[i-1]<nums[i])
                break;
        }
        
        for(int j=int(nums.size()-1); j>=i; --j){
            if(nums[j] > nums[i-1]){
                swap(nums[j], nums[i-1]);
                reverse(nums.begin()+i, nums.end());
                return;
            }
        }
        
    }
};


int main() {
    // insert code here...

    return 0;
}
