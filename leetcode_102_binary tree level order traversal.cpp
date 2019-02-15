/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *cur;
        while(!q.empty()){
            int len = q.size();//当前队列中的元素个数(当前层的所有结点数量)
            vector<int> t;
            while(len>0){// 依次处理该层的每个结点
                cur = q.front();
                q.pop();
                t.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                len--;
            }
            res.push_back(t);     
        }
        return res;
    }
};