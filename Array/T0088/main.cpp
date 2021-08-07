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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    // 倒叙插入，节约空间，且只需遍历一遍
    --m; --n;
    for (auto it = nums1.end() -1; it >= nums1.begin(); --it)
    {
        if (m < 0)
        {
            *it = nums2[n];
            --n;
            continue;
        }
        if (n < 0)
        {
            *it = nums1[m];
            --m;
            continue;
        }


        if(nums1[m] > nums2[n])
        {
            *it = nums1[m];
            --m;
        }
        else
        {
            *it = nums2[n];
            --n;
        }
    }
}
};

int main() {
    // insert code here...
    
    return 0;
}
