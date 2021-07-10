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

//思路是便利所有元素，用三个数组判断遍历过的元素是否在先前出现过，而违反了数独的要求
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> col(9,vector<bool>(9,false));
        vector<vector<bool>> cell(9,vector<bool>(9,false));
        
        char current_element;
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                current_element = board[i][j];
                if(current_element == '.')
                    continue;
                else
                    if(row[i][static_cast<int>(current_element - '1')] ||
                       col[j][static_cast<int>(current_element - '1')] ||
                        cell[(i/3)*3 + j/3][static_cast<int>(current_element - '1')] )
                        return false;

                    else
                    {
                        row[i][static_cast<int>(current_element - '1')] = true;
                        col[j][static_cast<int>(current_element - '1')] = true;
                        cell[(i/3)*3 + j/3][static_cast<int>(current_element - '1')] = true;
                    }
            }
        }
        return true;
    }
};
int main() {
    // insert code here...

    return 0;
}
