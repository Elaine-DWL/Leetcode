#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 这段代码调不粗来。。。  不知道哪里错了
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size()/2 == 0) return nums.size();
        unordered_map<int, int> myhash;
        int fre = 1;//众数的频率
        for(int num:nums){
            myhash[num]++;
            fre = max(fre, myhash[num]);
        }
        vector<int> zhong;//存储所有的众数
        for(auto m:myhash){
            if(m.second == fre) zhong.push_back(m.first);
        }
        int min_len = LONG_MAX;
        for(int i=0; i<zhong.size(); i++){
            int start = find(nums.begin(), nums.end(), zhong[i]) - nums.begin();
            int tail = nums.rend() - find(nums.rbegin(), nums.rend(), zhong[i]) -1;
            min_len = min(min_len, tail-start+1);
        }
        return min_len;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]].push_back(i);
        int degree=0;
        for(auto t:mp) degree = max(degree, int(t.second.size()));
        int shortest = nums.size();
        for(auto t:mp){
            if(t.second.size()==degree) shortest = min(shortest, t.second.back()-t.second[0]+1);
        }
        return shortest;
    }
};
int main()
{
    vector<int> nums({1,2,3,2,5,6});
    int x = nums.rend() - find(nums.rbegin(), nums.rend(), 2) - 1;
    cout<<x;
}
