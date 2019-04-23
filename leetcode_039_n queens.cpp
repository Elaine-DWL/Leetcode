// N皇后问题  用回溯法求解
class Solution {
public:
    // 先放置每一行的元素   深度优先遍历 如果不满足要求  则终止递归返回上一级（回溯）
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        // if(n<=3) return res;
        vector<string> init(n, string(n, '.'));
        dfs(0, init, res);
        return res;
    }
    bool isSafe(vector<string> init, int row, int col){// 最后的一个皇后位置是 [row][col]
        for(int i=0; i<row; i++){
           if(init[i][col]=='Q') return false;
       }
        for(int i=row-1, j=col-1; i>=0&&j>=0; i--,j--){// 判断左对角线上的所有元素是否有皇后
            if(init[i][j] == 'Q') return false;
        }
        for(int i=row-1, j=col+1; i>=0&j<=init.size(); i--,j++){
            if(init[i][j] == 'Q') return false;
        }
        return true;
    }
    void dfs(int row, vector<string> &init, vector<vector<string>> &res){
        if(row >= init.size()){
            res.push_back(init);
            return;
        }
        // 给第row行放置皇后
        for(int i=0; i<init.size(); i++){
            init[row][i] = 'Q';
            if(isSafe(init, row, i)){// 如果目前为止 0~row行的元素是安全的
                dfs(row+1, init, res);
            }
            init[row][i] = '.';
        }
    }
};