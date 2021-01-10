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
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = int(nums.size()-1);
        int mid;
        int first = -2, last = -2;
        while(left<=right){
            mid = left + (right-left)/2;
            if ( nums[mid] < target )
                left = mid + 1;
            else {
                right = mid - 1;
                first = right;
            }
        }
        left = 0;
        right = int(nums.size()-1);
        while (left<=right) {
            mid = left + (right-left)/2;
            if ( nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
                last = left;
            }
                
            
        }
        //cout<<first<<' '<< last;
        if (first == -2 || last == -2)
            return vector<int>{-1,-1};
        else if (nums[first+1]==target && nums[last-1]==target)
            return vector<int>{first+1,last-1};
        else
            return vector<int>{-1,-1};
    }
};

int main() {
    // insert code here...
    vector<int> nums = {5,7,7,8,8,10};
    Solution sol;
    sol.searchRange(nums, 8);
    return 0;
}
