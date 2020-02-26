#include<iostream>
#include<queue>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int index = 0;
        char tmp;

        if (strs.size()==0)
            return result;
        if (strs.size()==1)
            return strs[0];
        if (strs[0].size()==0)
            return result;
        

        while (index<strs[0].size())
        {
            tmp = strs[0][index];
            //cout<<tmp<<endl;
            for (int i=1; i<strs.size(); ++i)
            {
                //cout<<tmp<<' '<<strs[i][index]<<endl;
                if (tmp!=strs[i][index])
                    return result;
            }
            //cout<<"======="<<endl;
            ++ index;
            result += tmp;

        }
        return result;
    }
};

int main()
{
    
    Solution T14;
    
    return 0;
}