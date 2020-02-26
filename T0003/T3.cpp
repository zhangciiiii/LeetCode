#include<iostream>
#include<queue>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int max_len=0, current_len=0;
        int start=0,end=0,current_index=0;
        
        while(end<s.size())
        {
            
            for (current_index=start; current_index<end; ++ current_index)
            {           
                if (s[current_index]==s[end])
                {
                    start = current_index+1;
                    max_len = max(max_len, current_len);                    
                    break;
                }
                
            }
            // cout<<current_len<<' '<<start<<' '<<end<<endl;
            current_len = end-start+1;
            ++end;
            
        }

        return max(max_len, current_len);
        

    }
};

int main()
{
    string x = "aaaaa";
    cout<<x<<endl;
    Solution T3;
    cout<<T3.lengthOfLongestSubstring(x);
    return 0;
}