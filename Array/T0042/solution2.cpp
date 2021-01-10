//
//  main.cpp
//  LeetCodeTest
//
//  Created by ZhangChi on 2020/12/28.
//

#include <iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int Result = 0;
        int Size = int(height.size());
        
        if (Size<=2)
            return Result;
        
        int LeftHighest[Size];
        int RightHighest[Size];
        
        LeftHighest[0] = height[0];
        RightHighest[Size-1] = height[Size-1];
        
        for (int i = 1; i < Size; ++i)
            LeftHighest[i] = max(LeftHighest[i-1], height[i]);
        
        for (int i = Size - 2; i > -1; --i)
            RightHighest[i] = max(RightHighest[i+1], height[i]);
        
        for (int i = 0; i < Size; ++i)
        Result += min(LeftHighest[i], RightHighest[i])-height[i];
        
        return Result;
    }
};


int main() {
    // insert code here...
    vector<int> nums = {3,4,-1,1};
    Solution sol;
    
    return 0;
}
