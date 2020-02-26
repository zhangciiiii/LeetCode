#include<iostream>
#include<queue>
#include <set>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int tmp = 0;
        bool negative_flag = false;
        bool not_flaged = true;
        bool if_begin = true;
        bool start=false;
        for(int i=0; i<str.size();++i)
        {
            if (if_begin)
            {
                if_begin=false;
                while(str[i]==' ')
                    ++i;
            }
            
            
            if (str[i]!='-' && str[i]!='+' && (str[i]<'0' || str[i]>'9')  )
                break;
            if ((str[i]=='-' || str[i]=='+' ) && start)
                break;
            if (str[i]=='-' && not_flaged)
            {
                negative_flag = true;
                not_flaged = false;
                continue;
            }
            if (str[i]=='+' && not_flaged)
            {
                negative_flag = false;
                not_flaged = false;
                continue;
            } 
            if(!not_flaged && (str[i]=='+' || str[i]=='-'))
                return 0;
            
            tmp = int(str[i]-'0');

            if(!negative_flag && (result> INT_MAX/10 || (result == INT_MAX/10 && tmp>7) ))
                return INT_MAX;
            if(negative_flag && (result> -INT_MIN/10 || (result == -INT_MIN/10 && tmp>=8) ))
                return INT_MIN;
            

            result = result*10 + tmp;
            start = true;
               
            
        }

        if (negative_flag)
            return (-result);
        else
            return result;
    }
};

int main()
{
    Solution T8;
    string x;
    x = "  123";
    T8.myAtoi(x);
    return 0;
}