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
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = int(nums.size()-1);
        int mid = 0;
        while(left <= right){
            mid = left + (right - left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid +1;
        }
        return left;
    }
};
int main() {
    // insert code here...
    vector<int> nums = {1,3,5,6};
    Solution sol;
    cout<<sol.searchInsert(nums, 0)<<endl;
    return 0;
}
