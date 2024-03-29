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
    vector<int> plusOne(vector<int>& digits) {
        vector<int> vResult;
        bool bIf10 = false;
        for(auto it = digits.end()-1; it != digits.begin()-1; --it)
        {
            if(it == digits.end()-1)
            {
                bIf10 = (*it+1)/10;
                vResult.push_back((*it + 1)%10);
                continue;
            }
            if(!bIf10)
                vResult.push_back((*it)%10);
            else
            {
                bIf10 = (*it+1)/10;
                vResult.push_back((*it + 1)%10);
            }
        }
        if(bIf10)
            vResult.push_back(1);
        reverse(vResult.begin(), vResult.end());
        return vResult;
    }
};
    


int main() {
    // insert code here...

    
    return 0;
}
