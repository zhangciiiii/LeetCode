#include<iostream>
#include<queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int result = (right-left)*(min(height[left],height[right]));

        while(left!=right)
        {
            //cout<<left<<' '<<right<<' '<<result<<endl;
            if (height[left]<height[right])
                ++left;
            else
                --right;
            result = max(result, (right-left)*(min(height[left],height[right])));            

        }
        return result;
    }
};

class Solution2{
    public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return -1;
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            if(height[i] < height[j]) ++i;
            else --j;
        }
        return res;
    }
};

int main()
{
    int a[4] = {1,2,4,3};
    vector<int> x(a, a+4);
    Solution T11;
    cout<<T11.maxArea(x);
    return 0;
}