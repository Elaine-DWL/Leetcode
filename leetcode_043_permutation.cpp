// 思路一  按自己的理解写的代码
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        for(int i=0; i<nums.size(); i++){// 一次固定第一个数
            vector<int> tmp;
            swap(nums[i], nums[0]);
            // sort(nums.begin()+i+1, nums.end()); // 如果要保证字典序   这一句需要加上
            tmp.push_back(nums[0]);
            generate(nums, 1, tmp, res);  
        }
        return res;
    }
    void generate(vector<int> nums, int start, vector<int> &tmp, vector<vector<int>> &res){// 注意这里的第一个形参不能传引用
        if(start==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            swap(nums[i], nums[start]);
            // sort(nums.begin()+start+1, nums.end()); // 如果要保证字典序 这一句需要加上
            tmp.push_back(nums[start]);
            generate(nums, start+1, tmp, res);
            tmp.pop_back();
        }
    }
};

// 思路二  别人的更简洁的代码
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generate(nums, 0, result);
        return result;
    }
    void generate(vector<int> nums, int start, vector<vector<int>> &res){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            swap(nums[i], nums[start]);
            generate(nums, start+1, res);
            swap(nums[i], nums[start]);
        }
    }
};