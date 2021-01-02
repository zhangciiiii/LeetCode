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
    int removeDuplicates(vector<int>& nums) {
        int left=0,right=1;
        if (nums.size()<2 )
            return int(nums.size());
        for ( ; right<=nums.size()-1; ++right){
            if (nums[left] != nums[right]){
                left++;
                nums[left] = nums[right];
            }
        }
        return  left+1;
    }
};


int main() {
    // insert code here...

    return 0;
}
