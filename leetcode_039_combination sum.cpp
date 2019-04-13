// 思路一 递归实现
// https://www.cnblogs.com/grandyang/p/4419259.html
class Solution{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates int target){
		vector<vector<<int>> res;
		combinationSumDFS(candidates, target, 0, {}, res);
		return res;
	}
	// target 是当前要凑的数
	void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int> out, vector<vector<int>>& res){
		if(target < 0) return;
		if(target == 0){
			res.push_back(out);
			return;
		}
		// 用candidates中的数，一个一个去试
		for(int i=start; i<candidates.size(); i++){
			out.push_back(candidates[i]);
			combinationSumDFS(candidates, target-candidates[i], i, out, res);
			out.pop_back();
		}
	}
}

// 自己写的：
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0 || target<=0) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        record(candidates, target, tmp, res);
        return res;
    }
    void record(vector<int> candidates, int target, vector<int> &cur, vector<vector<int>> &res){
        if(target==0){
            res.push_back(cur);
            return;
        }
        if(target<0) return;
        int n=candidates.size();
        for(int i=0; i<n; i++){
            if(target < candidates[i]) break;
            if(cur.size()>0 && candidates[i]<cur.back()) continue; // 保证每种组合中的数是非递减的  相当于剪枝，避免重复情况    举个例子也就是说[2, 2, 3], [2, 3, 2], [3, 2, 2]中，只有[2, 2, 3]满足要求，所以可以避免重复结果
            cur.push_back(candidates[i]);
            record(candidates, target-candidates[i], cur, res);
            cur.pop_back();
        }
    }
    
    
};