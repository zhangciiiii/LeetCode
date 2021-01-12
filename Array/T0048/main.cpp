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
    void rotate(vector<vector<int>>& matrix) {
        int MatrixSize = int(matrix[0].size());
        int mid = MatrixSize/2;
        for(int i = 0; i < mid; ++i){
            for(int j = 0; j < MatrixSize; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[MatrixSize-1-i][j];
                matrix[MatrixSize-1-i][j] = tmp;
            }
        }
        
        for(int i = 0; i < MatrixSize - 1; ++i){
            for (int j = i+1; j < MatrixSize; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
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
