#include<iostream>
#include<queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result(numRows);
        int T = 2*numRows-2;
        if (T==0)
            return s;
        int insert_index;
        for(int i=0;i<s.size();++i)
        {
            insert_index = i%T;
            if (insert_index<numRows)
            {
                result[insert_index].push_back(s[i]);
                continue;
            }
            else
            {
                result[T-insert_index].push_back(s[i]);
                continue;
            }
            
        }
        string final;
        for (int j=0; j<numRows;++j)
            final += result[j];
        return final;
    }
};

int main()
{
    string s = "LEETCODEISHIRING";
    
    Solution T6;
    cout<<T6.convert(s,4);
    return 0;
}