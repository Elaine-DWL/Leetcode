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