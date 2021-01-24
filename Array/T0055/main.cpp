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
    bool canJump(vector<int>& nums) {
        
        int Target = int(nums.size()-1);
        int CurrentPosition = int(nums.size()-1);
        while (CurrentPosition >= 0){
            if (nums[CurrentPosition] + CurrentPosition >= Target)
                Target = CurrentPosition;
            --CurrentPosition;
        }
        if (Target == 0)
            return true;
        else
            return false;
    }
};

int main() {
    // insert code here...
    vector<int> nums = {3,4,-1,1};
    Solution sol;
    
    return 0;
}
