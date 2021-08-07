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
    int largestRectangleArea(vector<int>& heights)
{
    // 用于储存入栈元素ID
    stack<int> snHeightID;
    int result = 0;
    int PopID = 0;
    // 为了让所有元素最后都出栈，需要在最后加上一个最小的元素
    heights.push_back(-1);


    for (int i = 0; i < heights.size(); ++i)
    {
        // 维持单调栈
        if (snHeightID.empty() )
        {
            if (heights[i]>0)
                snHeightID.push(i);
            continue;
        }


        // 当前元素大于等于栈顶，则可以维持单调栈结构，入栈
        if(heights[i] >= heights[snHeightID.top()] )
            snHeightID.push(i);
        // 检测到当前元素要小于栈顶对应元素
        else
        {
            // 内部元素出栈，直到当前元素可以入栈
            while(heights[i] <= heights[snHeightID.top()])
            {
                PopID = snHeightID.top();
                snHeightID.pop();
                // 计算Pop出来的矩形面积，每弹出一个就要算一次，因为是单调栈所以当前弹出的是高度最小的
                result = max(result, (i - PopID)*heights[PopID]);
                if(snHeightID.empty())
                    break;
            }
            // 当前被弹出来的ID重新入栈，并把其对应的高度设为当前i的对应高度，以此削掉高出的部分
            snHeightID.push(PopID);
            heights[PopID] = heights[i];
        }
    }
    return result;
}
};

int main() {
    // insert code here...
    
    return 0;
}
