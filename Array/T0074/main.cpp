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
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int nRowSize = matrix.size();
    int nColSize = matrix[0].size();
    int left = 0; int right = nRowSize*nColSize - 1;
    int mid; int i; int j;
    while(left <= right)
    {
        mid = (left+right)/2;


        i = mid/nColSize;
        j = mid%nColSize;
    
        
        
        if(matrix[i][j] > target)
            right = mid -1;
        if(matrix[i][j] < target)
            left = mid + 1;
        if(matrix[i][j] == target)
            return true;
    }
    return false;
    }
};

int main() {
    // insert code here...
    
    return 0;
}
