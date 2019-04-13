class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(target<=0 || candidates.size()==0) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        record(candidates, target, 0, tmp, res);
        return res;
    }
    void record(vector<int> &candidates, int target, int start, vector<int> &cur, vector<vector<int>> &res){
        if(target==0){
            res.push_back(cur);
            return;
        }
        if(target<0) return;
        for(int i=start; i<candidates.size();){
            if(target<candidates[i]) break;
            cur.push_back(candidates[i]);
            record(candidates, target-candidates[i], i+1, cur, res);
            cur.pop_back();
            while(i<candidates.size()-1 && candidates[i+1]==candidates[i]) i++;// avoid duplicate case
            i++;
        }
    }
};