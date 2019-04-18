// 这一题是在43题的基础上进行改进
// 43题中，数组中不存在同样的数
// 本题中，数组中是可能含有同样的数的
// 每一个交换前，如果有多个一样的数，那么只进行一次交换到前面  以避免出现重复的情况


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 可能含有重复数  返回所有可能的全排列
        // 每次交换的时候   如果某个数前面的数已经交换过，那么直接跳过这个数
        vector<vector<int>> res;
        generate(nums, 0, res);
        return res;
    }
    void generate(vector<int> nums, int start, vector<vector<int>> &res){
        if(start >= nums.size()){
            res.push_back(nums);
            return;
        }
        map<int, int> m;
        for(int i=start; i<nums.size(); i++){
            if(m.find(nums[i])==m.end()){// 前面没有重复的
                m[nums[i]] = 1;
                swap(nums[i], nums[start]);
                if(start+1==nums.size()){
                    res.push_back(nums);
                    continue;
                }
                generate(nums, start+1, res);
            }
        }
    }
};