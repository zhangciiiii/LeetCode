#include<iostream>
#include<queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int nums_list[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string str_list[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int index = 0;
        string result;
        while(true)
        {
            while(num>=nums_list[index])
            {
                num -= nums_list[index];
                result += str_list[index];
                cout<<num<<endl;
            }
            if (num==0)
                return result;
            ++index;
        }
    }
};

int main()
{
    Solution T11;
    int x=3;
    T11.intToRoman(x);
    
    return 0;
}