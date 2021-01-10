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
    int trap(vector<int>& height) {
        int Result = 0;
        int Size = int(height.size());
        if (Size < 3)
            return Result;
        int i = 0;
        stack<int> idStack;
        idStack.push(i);
        ++i;
        
        while ( i < Size) {

            while(! idStack.empty() && height[i] > height[idStack.top()]){
                int pop_buttom = height[idStack.top()];
                idStack.pop();
                if (idStack.empty())
                    break;
                Result += (i - idStack.top() - 1) *
                    (min(height[i],height[idStack.top()]) - pop_buttom);
            }
            idStack.push(i);
            ++i;
        
            
        }
        
        return Result;
    }
};

int main() {
    // insert code here...
    vector<int> nums = {3,4,-1,1};
    Solution sol;
    
    return 0;
}
