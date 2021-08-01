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
    

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() <= 1)
        return nums.size();
    // itLeft代表新数组的末尾（itLeft+1是空）
    auto itLeft = nums.begin();
    // itRight代表遍历数据的当前位置
    auto itRight = nums.begin()+1;
    // nCurrentNumCounter记录itLeft的元素出现了多少次
    int nCurrentNumCounter = 0;


    // 当遍历还未结束
    while(itRight != nums.end())
    {
        //检查itRight元素是否与itLeft相同：
        //若否，则右移动itLeft并更新元素
        if(*itLeft != *itRight)
        {
            ++itLeft;
            *itLeft = *itRight;
            ++itRight;
            nCurrentNumCounter = 0;
        }
        //若是，则判断该元素是否出现了两次
        else
        {
            if(nCurrentNumCounter == 0)
            {
                ++itLeft;
                *itLeft = *itRight;
                ++itRight;
                ++nCurrentNumCounter;
            }
            else 
            {
                ++itRight;
            }
        }
    }
    nums.erase(itLeft+1,itRight);
    return nums.size();
}
};

int main() {
    // insert code here...
    
    return 0;
}
