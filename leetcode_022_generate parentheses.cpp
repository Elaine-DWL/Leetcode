class Solution {
public:
    void recursive(string str, int l, int r, vector<string> &res){
        if(l > r) return;
        else if(l==0 && r==0){
            res.push_back(str);
            return;
        }
        else if(l < r){
            if(l>0) recursive(str+"(", l-1, r, res);
            recursive(str+")", l, r-1, res);
            
        }
        else if(l == r){
            recursive(str+"(", l-1, r, res);
            recursive(str+")", l, r-1, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursive("", n, n, res);
        return res;
    }
};