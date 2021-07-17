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
#include<queue>
using namespace std;

// 考点在于如何控制空间复杂度
// 有O(n)级别的复杂度，但是我觉得会O(m+n)就够了
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

