#include<iostream>
#include<queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 假设num1是更短的那个
        if (nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int mid_index;
        int nums1_size = nums1.size(), nums2_size = nums2.size();

        mid_index = (nums1_size+nums2_size)/2;
        
        int start=0, end=nums1_size-1;
        int index1 = (end-start)/2;
        int index2 = mid_index-index1-2;
        double result;

        while(index1>=0 && index1<nums1_size)
        {
            
            if (nums1[index1]<nums2[index2+1] && nums2[index2]<nums1[index1+1])
                break; //无特殊情况的成功二分

            if (nums2[index2]>nums1[index1+1] && index1<(nums1_size-1)) // i往右移动
            {
                start = index1;
                index1=(start+end)/2;
                index2 = mid_index-index1-2;
                cout<<"right"<<endl;
                
            }

            else if ( nums1[index1]>nums2[index2+1] && index1>0 ) // i往左移动
            {
                end = index1;
                index1=(start+end)/2;
                index2 = mid_index-index1-2;
                cout<<"left"<<endl;
                
            }
            
            if ( nums1[index1]>nums2[index2+1] && index1==0 ) // i往左移动
            {
                index1=-1;
                index2 = mid_index-index1-2;
                cout<<index1<<' '<<index2<<endl;
                break;
            }
            
            
        }



        if ((nums1.size()+nums2.size())%2 == 0)
        {
            if (index1!=-1 && index2!=-1 && index1!=nums1_size-1 && index2!=nums2_size-1)
            {
                result = (max(nums1[index1],nums2[index2])+min(nums1[index1+1],nums2[index2+1]))/2.0;
                return result;
            }

            
            
        }
        else 
        {
            result = max(nums1[index1],nums2[index2]);
            return result;
        }

    }
};

int main()
{ 
    int a[4]={1,3};
    int b[4]={2};
    vector<int> v1(a,a+2);
    vector<int> v2(b,b+1);
    Solution T4;
    cout<<T4.findMedianSortedArrays(v1,v2);



    return 0;
}