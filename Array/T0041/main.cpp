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
    int firstMissingPositive(vector<int>& nums) {
        int N = int(nums.size());
        for (int i = 0; i < N; ++i){
            if (nums[i] <= 0 || nums[i] > N)
                nums[i] = N+1;
        }
        
        for (int i = 0; i < N; ++i){
            int absNum = abs(nums[i]);
            if (absNum < N+1)
                nums[absNum-1] = -abs(nums[absNum-1]);
        }

        for (int i = 0; i < N; ++i ){
            if (nums[i] > 0)
                return i+1;
        }
        
        return N+1;
    }
};

int main() {
    // insert code here...
    vector<int> nums = {3,4,-1,1};
    Solution sol;
    cout<<sol.firstMissingPositive(nums)<<endl;
    cout<<nums[1]<<endl;
    return 0;
}
