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
    void sortColors(vector<int>& nums) {
    SortPart(nums, 0, nums.size()-1);
}


void SortPart(vector<int>& nums, int left, int right)
{
    if(left >= right)
        return;
    bool l2r = true;
    int initialLeft = left;
    int initialRight = right;
    while(left < right)
    {
        if(l2r)
        {
            if(nums[left] <= nums[right])
                ++left;
            else
            {
                swap(nums[left], nums[right]);
                l2r = false;
            }
        }
            
        else
        {
            if(nums[right] >= nums[left])
                --right;
            else
            {
                swap(nums[left], nums[right]);
                l2r = true;
            }
        }       
    }
    SortPart(nums, initialLeft, left-1);
    SortPart(nums, right+1, initialRight);
}
    
};

int main() {
    // insert code here...
    
    return 0;
}
