//这道题和026差不多，依然是有序数组，额外的空间复杂度必须是o(1)
//只是这里要求如果原来数组中某个元素个数超过了2，则只保留2个，原来只有一个的话，还是保留一个
//解法和026差不多一个思路，依然设置两个游标，对于数字序列abc，只有在a=!b或者b!=c的情况下，才能把c留下
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<= 2) return nums.size();
        int len=2, i=1;
        vector<int>::iterator ite = nums.begin()+2;
        for(;ite<nums.end();ite++){
            if(nums[i-1]!=nums[i] || nums[i]!=*ite){
                nums[i+1] = *ite;
                i++;
                len++;
            }
        }
        return len;

    }
};

int main()
{
    vector<int> nums;
    int t;
    while(scanf("%d", &t)!=EOF){
        nums.push_back(t);
    }
    Solution A;
    printf("%d",A.removeDuplicates(nums));
}
