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
        return left;
    }
    int search(vector<int>& nums, int target) {
        int divide = findMin(nums);
        int left, right;
        if (target == nums[0])
            return 0;
        if (target > nums[0] && divide != 0){
            left = 0;
            right = divide-1;
        }
        else{
            left = divide;
            right = int(nums.size()-1);
        }

        int mid;
        while (left <= right){
            mid = (left+right)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;
    }
};

int main() {
    // insert code here...
    vector<int> nums = {1,3};
    Solution sol;
    cout<<sol.search(nums, 3);
    return 0;
}
