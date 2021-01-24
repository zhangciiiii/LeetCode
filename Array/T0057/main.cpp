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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int i = 0;
        vector<vector<int>> Result;
        if (intervals.size()==0)
        {
            Result.push_back(newInterval);
            return Result;
        }
            
        
        if (intervals[0][0] > newInterval[0])
            Result.push_back(newInterval);
        
        else
        {
            for (i = 0; i < intervals.size(); ++i){
                if (intervals[i][0] > newInterval[0])
                    break;
                else
                    Result.push_back(intervals[i]);
            }
            
            if (Result.back()[1] >= newInterval[0])
                Result.back()[1] = max(Result.back()[1], newInterval[1]);
            else
                Result.push_back(newInterval);
        }
        
        for (i; i < intervals.size(); ++i){
            if (Result.back()[1] >= intervals[i][0])
                Result.back()[1] = max(Result.back()[1], intervals[i][1]);
            else
                Result.push_back(intervals[i]);
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
