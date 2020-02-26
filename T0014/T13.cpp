#include<iostream>
#include<queue>
#include <set>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        map<char, int> char_int;
        int result=0;
        char_int['M']=1000;
        char_int['D']=500;
        char_int['C']=100;
        char_int['L']=50;
        char_int['X']=10;
        char_int['V']=5;
        char_int['I']=1;

        int index=0;

        while (index<s.size()-1)
        {
            if (char_int[s[index]]>=char_int[s[index+1]])
                result += char_int[s[index]];
            else
                result -= char_int[s[index]];
            //cout<<result<<endl;
            ++index;
        }
        result += char_int[s[index]];
        return result;
        
    }
};

int main()
{
    
    Solution T13;
    string x = "III";
    T13.romanToInt(x);
    return 0;
}