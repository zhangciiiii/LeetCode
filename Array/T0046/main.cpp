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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        mBackTrack(nums, result, 0);
        return result;
    }
    
    //回溯算法：思路是将当前指针所在的元素与数组后面的元素都相交换，
    //移动指针，指针前的元素相当于固定了，而指针后的元素需要调用递归继续交换
    void mBackTrack(vector<int>& nums, vector<vector<int>>& result, int ExchangedID)
    {
        //当指针到达数组末尾，代表所有元素都固定了，压入结果中
        if (ExchangedID == nums.size())
            result.push_back(nums);
        
        //指针ExchangedID以前的元素代表已经固定，需要关心其后的元素
        //采用遍历，交换指针ExchangedID的元素与其后遍历的元素，并在固定后进入下一轮递归
        //递归结束后需要交换数组元素还原。
        for(int i = ExchangedID; i < nums.size(); ++ i)
        {
            swap(nums[ExchangedID], nums[i]);
            mBackTrack(nums, result, ExchangedID + 1);
            swap(nums[ExchangedID], nums[i]);
        }
        return;
    }
};
int main() {
    // insert code here...
    vector<int> nums{1,2,3};
    
    for(auto it = nums.begin(); it != nums.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}

