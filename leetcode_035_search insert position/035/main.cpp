// 这道题的题意是给定一个无重复元素的已排序数组和一个目标值，查找该目标值的下标，
// 如果不存在的话  返回将该元素插入后的坐标
// 如果是顺序搜索的话 复杂度是o(n)  二分搜索的话就是o(logn)
#include <iostream>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int p=0, q=nums.size()-1;
        int n=(p+q)/2;
        while(p<=q){
            if(target==nums[n]) return n;
            if(target > nums[n]){
                p = n+1;
            }
            else q = n-1;
            n = (p+q)/2;
        }
        return p;

    }
};
int main(){

}
