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
    int removeElement(vector<int>& nums, int val) {
        int left = -1;
        int right = 0;
        int NumSize = int(nums.size());
        for (; right <= NumSize-1; ++right){
            if(nums[right] != val){
                ++left;
                nums[left] = nums[right];
            }
        }
        return left+1;
    }
};


int main() {
    // insert code here...

    return 0;
}
