#include<iostream>
#include<queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result=0;
        int tmp=0;
        while(x!=0)
        {
            tmp = x%10;
            x = x/10;
            if (result>INT_MAX/10)
                return 0;
            if (result==INT_MAX/10 && tmp>7)
                return 0;
            if (result<INT_MIN/10)
                return 0;
            if (result==INT_MAX/10 && tmp<-8)
                return 0;
            result = result*10 + tmp;
        }
        return result;
    }
};
int main()
{
    return 0;
}