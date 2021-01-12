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
    int jump(vector<int>& nums) {
        int Result = 0;
        int CurrentPosition = 0;
        while (CurrentPosition < nums.size()-1){
            ++Result;
            if(CurrentPosition + nums[CurrentPosition] >= nums.size()-1)
                return Result;
            int MaxStepLen = 0, Max_i = 0;
            for (int i = 1; i <= nums[CurrentPosition]; ++i){
                if (i + nums[CurrentPosition+i] > MaxStepLen){
                    MaxStepLen = i + nums[CurrentPosition+i];
                    Max_i = i;
                }
            }
            
            CurrentPosition += Max_i;
        }
        return Result;
    }
};

int main() {
    // insert code here...
    vector<int> nums = {3,4,-1,1};
    Solution sol;
    
    return 0;
}
