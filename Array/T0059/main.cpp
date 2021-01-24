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
    vector<vector<int>> generateMatrix(int n) {
        int left, right, up, down;
        left = 0;
        right = n-1;
        up = 0;
        down = n-1;
        int i = 1;
        vector<vector<int>> Result(n,vector<int>(n));
        while (left <= right){
            Circle(i, left, right, up, down, Result);
            ++left;
            --right;
            ++up;
            --down;
        }
        //cout<<i;
        return Result;
        
    }
    
    void Circle(int &i, int left, int right, int up, int down, vector<vector<int>>& Result){
        if (left == right)
            Result[left][up] = i;
        else {
            for(int j = left; j < right; ++j){
                Result[up][j] = i;
                ++i;
            }
            for(int j = up; j < down; ++j){
                Result[j][right] = i;
                ++i;
            }
            for(int j = right; j > left; --j){
                Result[down][j] = i;
                ++i;
            }
            for(int j = down; j > up; --j){
                Result[j][left] = i;
                ++i;
            }
            
        }

    }
    
};
    


int main() {
    // insert code here...
    vector<int> nums = {3,4,-1,1};
    Solution sol;
    
    return 0;
}
