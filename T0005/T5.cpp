#include<iostream>
#include<queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string& s) {
        

        int start=0, end=s.size()-1;
        int max_len = 0;
        int max_start=0, max_end=0;
        int compare=1;

        int current_center1=0, current_center2=1;

        //cout<<end+1<<' '<<"nb";
        if (end+1<2)
            return s;

        while (current_center1<end) // 一个个中心地遍历
        {
            while((current_center1-compare)>start && (current_center1+compare)<end) // 一个个格子地去比较
            {
                
                if (s[current_center1-compare]==s[current_center1+compare]) // 当满足回文条件，继续
                {
                    compare++;
                    //cout<<current_center1<<' '<<compare<<endl;
                }
                else if (s[current_center1-compare]!=s[current_center1+compare]) // 不满足回文条件时停止
                {
                    //cout<<"stop"<<endl;
                    if ((2*(compare-1)+1)>max_len) // 停止时判断长度
                        {
                            max_len = (2*(compare-1)+1);
                            max_start = current_center1-(compare-1);
                            max_end = current_center1+(compare-1);
                        }
                    compare = 1;
                    break;
                }
            } // 当因为超了end和start的时候也要比较

            if ((current_center1-compare)<=start || (current_center1+compare)>=end)
            {
                //cout<<"out"<<endl;
                if (s[current_center1-compare]==s[current_center1+compare])
                {
                    //cout<<"still"<<endl;
                    compare++;
                    if ((2*(compare-1)+1)>max_len) // 判断长度
                        {
                            
                            max_len = (2*(compare-1)+1);
                            max_start = current_center1-(compare-1);
                            max_end = current_center1+(compare-1);
                        }
                    compare = 1;
                }

                else 
                {
                    if ((2*(compare-1)+1)>max_len) // 判断长度
                        {
                            
                            max_len = (2*(compare-1)+1);
                            max_start = current_center1-(compare-1);
                            max_end = current_center1+(compare-1);
                        }
                    compare = 1;
                }
            }

            ++current_center1;
            //cout<<"current_center1"<<' '<<current_center1<<endl;
        }

        
        

        current_center1=0;
        current_center2=1;
        compare=1;

        
        while (current_center1<end) // 一个个中心地遍历
        {
            while((current_center1-compare)>start && (current_center2+compare)<end) // 一个个格子地去比较
            {
                if(s[current_center1]!=s[current_center2])
                    break;

                
                if (s[current_center1-compare]==s[current_center2+compare]) // 当满足回文条件，继续
                {
                    compare++;
                    //cout<<current_center1<<' '<<compare<<endl;
                }
                else if (s[current_center1-compare]!=s[current_center2+compare]) // 不满足回文条件时停止
                {
                    //cout<<"stop"<<endl;
                    if ((2*(compare-1)+1)>max_len) // 停止时判断长度
                        {
                            max_len = (2*(compare-1)+2);
                            max_start = current_center1-(compare-1);
                            max_end = current_center2+(compare-1);
                        }
                    compare = 1;
                    break;
                }
            } // 当因为超了end和start的时候也要比较

            if ((current_center1-compare)<=start || (current_center2+compare)>=end)
            {
                //cout<<"out"<<endl;
                if (s[current_center1-compare]==s[current_center2+compare])
                {
                    //cout<<"still"<<endl;
                    compare++;
                    if ((2*(compare-1)+1)>max_len) // 判断长度
                        {
                            
                            max_len = (2*(compare-1)+2);
                            max_start = current_center1-(compare-1);
                            max_end = current_center2+(compare-1);
                        }
                    compare = 1;
                }

                else 
                {
                    if ((2*(compare-1)+1)>max_len) // 判断长度
                        {
                            
                            max_len = (2*(compare-1)+2);
                            max_start = current_center1-(compare-1);
                            max_end = current_center2+(compare-1);
                        }
                    compare = 1;
                }
            }

            //cout<<s[current_center1]<<s[current_center2]<<endl;
            if (s[current_center1]==s[current_center2] && max_len<2) 
            {
                max_len = 2;
                max_start = current_center1;
                max_end = current_center2;
            }

            ++current_center1;
            ++current_center2;

            //cout<<"current_center1"<<' '<<current_center1<<endl;
        }
        

        //cout<<max_start<<' '<<max_len<<endl;
        string s2(s,max_start,max_len) ;
        return s2;

    }
};

int main()
{
    string s = "ac";
    
    Solution T5;
    cout<<T5.longestPalindrome(s);
    return 0;
}