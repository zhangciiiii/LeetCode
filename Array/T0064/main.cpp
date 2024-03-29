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
    int minPathSum(vector<vector<int>>& grid) {
        int nMinPath[grid.size()][grid[0].size()];
        memset(nMinPath,0,sizeof(nMinPath));
        
        nMinPath[0][0] = grid[0][0];
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(i==0 && j>0)
                    nMinPath[i][j] = nMinPath[i][j-1] + grid[i][j];
                if(j==0 && i>0)
                    nMinPath[i][j] = nMinPath[i-1][j] + grid[i][j];
                if(i>0 && j>0)
                {
                    nMinPath[i][j]  = grid[i][j] +
                        min(nMinPath[i][j-1],nMinPath[i-1][j]);
                }
            }
        }
        return nMinPath[grid.size()-1][grid[0].size()-1];
    }
};
    


int main() {
    // insert code here...
    
    return 0;
}
