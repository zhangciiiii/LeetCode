#include<iostream>
#include<queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int raw = x;
        int result=0;
        int tmp=0;
        if (x<0)
            return false;
        while(x!=0)
        {
            tmp = x%10;
            x = x/10;
            if (result>=INT_MAX/10)
                return false;

            result = result*10 + tmp;
        }
        
        if (result==raw)
            return true;
        else
            return false;
    }
    
};


int main()
{
    return 0;
}