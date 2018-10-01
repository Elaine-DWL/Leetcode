// 题目大意是，给定一个数组和一个value值，删除该数组中的value
// 并且满足，剩下的元素都在原来数组的前列   额外的空间复杂度为o(1)
// 返回值是剔除所有的value后，数组中元素的大小
// 解题思路是，在原数组上进行操作，仍然是设置两个游标
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return nums.size();
        int i=0;
        vector<int>::iterator ite = nums.begin();
        for(; ite<nums.end(); ite++){
            if(*ite != val) nums[i++] = *ite;
        }
        return i;
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
    printf("%d", A.removeElement(nums, 2));

}
