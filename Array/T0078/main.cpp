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

    void backSource(vector<vector<int> >& vvnResult, vector<int>& vnCurrentVector, vector<int>& nums, int ptr)
    {
        if(ptr == nums.size())
        {
            vvnResult.push_back(vnCurrentVector);
            return;
        }
            
        
        vnCurrentVector.push_back(nums[ptr]);
        backSource(vvnResult, vnCurrentVector, nums, ptr+1 );
        vnCurrentVector.pop_back();
        backSource(vvnResult, vnCurrentVector, nums, ptr+1 );
    }


    vector<vector<int> > subsets(vector<int>& nums)
    {
        vector<vector<int> > vvnResult;
        vector<int> vnCurrentVector;
        backSource(vvnResult, vnCurrentVector, nums, 0 );
        return vvnResult;
    }
};

int main() {
    // insert code here...
    
    return 0;
}
