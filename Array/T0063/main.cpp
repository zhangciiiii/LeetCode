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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int  nPath [obstacleGrid.size()] [obstacleGrid[0].size()] ;
        memset(nPath,0,sizeof(nPath));
        if (obstacleGrid[0][0] != 1)
            nPath[0][0] = 1;
        for(int i = 0; i < obstacleGrid.size(); ++i)
        {
            for(int j = 0; j < obstacleGrid[0].size(); ++j)
            {
                if(i>0)
                    nPath[i][j] += nPath[i-1][j];
                if(j>0)
                    nPath[i][j] += nPath[i][j-1];
                if(obstacleGrid[i][j] == 1)
                    nPath[i][j] = 0;
                //cout << i << " " << j << " " << nPath[i][j] << endl;
            }
        }
        return nPath [obstacleGrid.size()-1] [obstacleGrid[0].size()-1];
    }
};
    


int main() {
    // insert code here...
    return 0;
}
