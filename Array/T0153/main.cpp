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
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = int(nums.size()-1);
        int mid;
        while (left < right){
            mid = (left+right)/2;
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};

int main() {
    // insert code here...
    vector<int> nums = {1,2};
    Solution sol;
    cout<<sol.findMin(nums);
    return 0;
}
