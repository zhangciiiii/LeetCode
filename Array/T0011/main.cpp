//
//  main.cpp
//  LeetCodeTest
//
//  Created by ZhangChi on 2020/12/28.
//

#include <iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> NumsLoc;
        map<int,int> HashTable;
        for (int i = 0; i <nums.size(); ++i){
            auto tmp = HashTable.find(target-nums[i]);
            if(tmp == HashTable.end() )
                HashTable.insert(pair<int, int> (nums[i], i));
            else{
                NumsLoc.push_back(tmp->second);
                NumsLoc.push_back(i);
                break;
            }
        }
        return NumsLoc;
    }
};

int main() {
    // insert code here...
    cout<< "Hello, World!\n";
    return 0;
}
