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
    void setZeroes(vector<vector<int>>& matrix) {
        bool *vbRow = new bool [matrix.size()] {false};
        bool *vbCol = new bool [matrix[0].size()] {false};
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                if(matrix[i][j] == 0)
                {
                    vbRow[i] = true;
                    vbCol[j] = true;
                }
            }
        }
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                if(vbRow[i] || vbCol[j])
                    matrix[i][j] = 0;
            }
        }
    }
};


int main() {
    // insert code here...
    
    return 0;
}
