// 判断一个数组中时否含有重复元素
// 思路1是直接暴力  两个循环  这里就不写了
// 思路2 是hash
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//    -------法2，哈希   18/18 36ms 36.62%
class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
        unordered_map<int, int> myhash;
        for(int i=0; i<nums.size(); i++){
            if(myhash.count(nums[i])==0) myhash[nums[i]]=1;
            else return true;
        }
        return false;
    }
};
////   -------法2：借助stl中的unique函数
class Solution {
public:
    bool containsDuplicate(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<int>::iterator new_end = unique(nums.begin(), nums.end());
        if(new_end < nums.end()) return true;
        return false;
    }
};
// ----法3 这是现在leetcode上最快的算法  4ms  我看不懂~~~
// [1,2,3,7,6,7] 该代码无法正确判断
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return false;
        for(int i=1; i<len; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i]>nums[j]) break;
                if(nums[i]==nums[j]) return true;
            }
        }
        return false;
    }
};
int main()
{
    vector<int> a({1,2,3,7,6,7});
    Solution A;
    if(A.containsDuplicate(a)) printf("true");
    else printf("false");
}
