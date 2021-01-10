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
    int trap(vector<int>& height) {
        int Result = 0;
        if (int(height.size()) == 0)
            return Result;
        int MaxValue = *max_element(height.begin(),height.end());
        
        for (int i = 1; i <= MaxValue; ++i){
            int left = 0, right = int(height.size()-1);
            while( height[left] < i )
                ++left;
            while( height[right] < i)
                --right;
            while (left < right) {
                ++left;
                if (height[left] < i)
                    ++Result;
            }
            
        }
        
        
        return Result;
    }
};
int main() {
    // insert code here...
    vector<int> nums = {3,4,-1,1};
    Solution sol;
    
    return 0;
}
