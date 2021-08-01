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
    void BackSource(vector<vector<int> >& vvnResult, vector<int>& vnCurrentVector, int currentPtr, int const n, int const k)
{
    // 存储的数字数目达到k个，作为结果之一存储。
    if (vnCurrentVector.size() == k)
    {
        vvnResult.push_back(vnCurrentVector);
        for(auto it = vnCurrentVector.begin(); it != vnCurrentVector.end(); ++it)
            cout << *it << " ";
        cout << endl;
        return;
    }


    // 遍历的数字到达上限，返回
    if(currentPtr == n+1)
        return;


    // 包含当前数字的情况
    vnCurrentVector.push_back(currentPtr);
    BackSource(vvnResult, vnCurrentVector, currentPtr+1, n, k);
    // 不包含当前数字的情况
    vnCurrentVector.pop_back();
    BackSource(vvnResult, vnCurrentVector, currentPtr+1, n, k);
}


vector<vector<int> > combine(int n, int k)
{
    vector<vector<int> > vvnResult;
    vector<int> vnCurrentVector;
    BackSource(vvnResult, vnCurrentVector, 1, n, k);
    return vvnResult;
}
};

int main() {
    // insert code here...
    
    return 0;
}
