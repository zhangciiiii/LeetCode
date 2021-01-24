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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> Result;
        
        int left = 0;
        int right = int(matrix[0].size()-1);
        int up = 0;
        int down =int(matrix.size()-1);
        
        while (left <= right && up <= down) {
            rectangle(matrix, Result, left, right, up, down);
            ++left;
            --right;
            ++up;
            --down;
        }
        return Result;
    }
    
    void rectangle(vector<vector<int>>& matrix, vector<int>& Result,
                    int left, int right, int up, int down) {
        if(up == down) {
            for(int i = left; i <= right; ++i)
                Result.push_back(matrix[up][i]);
            return;
        }
        if (left == right){
            for(int i = up; i <= down; ++i)
                Result.push_back(matrix[i][right]);
            return;;
        }
        for(int i = left; i < right; ++i)
            Result.push_back(matrix[up][i]);
        for(int i = up; i < down; ++i)
            Result.push_back(matrix[i][right]);
        for(int i = right; i > left; --i)
            Result.push_back(matrix[down][i]);
        for(int i = down; i > up; --i)
            Result.push_back(matrix[i][left]);
    }
};

int main() {
    // insert code here...
    vector<int> nums = {3,4,-1,1};
    Solution sol;
    
    return 0;
}
