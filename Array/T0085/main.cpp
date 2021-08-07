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
    

int maximalRectangle(vector<vector<char>>& matrix)
{
    vector<vector<int>> MaxLenInEachRow;
    vector<int> EachRow;
    if (matrix.size() ==0)
        return 0;
    if (matrix[0].size() ==0)
        return 0;


    // 遍历每一行
    for(int row = 0; row < matrix.size(); ++row)
    {
        EachRow.clear();
        for (int col = 0; col < matrix[0].size(); ++col)
        {
            // 将每个格子左边所构成的最大矩形面积进行存储
            if(matrix[row][col] == '0')
                EachRow.push_back(0);
            else
            {
                if (col == 0)
                    EachRow.push_back(1);
                else 
                    EachRow.push_back(EachRow[col -1]+1);
            }
        }
        MaxLenInEachRow.push_back(EachRow);
    }


    // 多加一行-1，使得有序栈可以完全吐出来
    EachRow.clear();
    for (int col = 0; col < matrix[0].size(); ++col)
        EachRow.push_back(-1);
    MaxLenInEachRow.push_back(EachRow);


    // 遍历每一列，采用有序栈的方法，计算以某坐标为右下角的构成的矩形所包围的最大面积
    int MaxSize = 0;
    stack<int> MyStack;
    int PopID = 0;
    for (int col = 0; col < MaxLenInEachRow[0].size(); ++col) 
    {
        while(!MyStack.empty())
            MyStack.pop();
        
        for(int row = 0; row < MaxLenInEachRow.size(); ++row) 
        {
            if(MyStack.empty())
            {
                if (MaxLenInEachRow[row][col]!=0)
                    MyStack.push(row);
                continue;
            }


            if (MaxLenInEachRow[MyStack.top()][col] <= MaxLenInEachRow[row][col] )
            {
                MyStack.push(row);
                continue;
            }      


            else
            {
                while(MaxLenInEachRow[MyStack.top()][col] > MaxLenInEachRow[row][col])
                {
                    PopID = MyStack.top();
                    MyStack.pop();
                    MaxSize = max(MaxSize, MaxLenInEachRow[PopID][col]*(row - PopID));
                    
                    if(MyStack.empty())
                        break;
                }
                MyStack.push(PopID);
                MaxLenInEachRow[PopID][col] = MaxLenInEachRow[row][col];
            }               
        }
    }
    return MaxSize;
}
};

int main() {
    // insert code here...
    
    return 0;
}
