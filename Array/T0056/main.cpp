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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2)
            return intervals;
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> Result;
        Result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > Result.back()[1])
                Result.push_back(intervals[i]);
            else
                Result.back()[1] = max(Result.back()[1], intervals[i][1]);
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
