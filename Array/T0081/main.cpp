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
    bool CheckMid(vector<int>& nums, int target, int left, int right)
{
    if(left > right)
        return false;
    int mid = (left + right)/2;
    if (nums[mid] == target)
        return true;
    
    if(nums[mid] < target)
        return CheckMid(nums, target, mid+1, right);
    else 
        return CheckMid(nums,target, left, mid-1); 
    
}


bool search (vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    return CheckMid(nums, target, 0, nums.size()-1);
}
};

int main() {
    // insert code here...
    
    return 0;
}
