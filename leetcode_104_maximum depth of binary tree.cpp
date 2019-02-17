/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 方法一  深度优先遍历  也就是递归
class Solution {
public:
    // 求二叉树的深度    递归实现
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        // int left=1+maxDepth(root->left), right=1+maxDepth(root->right);
        // return left>right?left:right;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};
// 方法二  广度优先遍历的过程中 同时记录树的深度
class Solution {
public:
    // 求二叉树的深度    递归实现
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode *> q;
        TreeNode *cur=root;
        q.push(cur);
        int depth=0;
        while(!q.empty()){
            depth++;
            int n=q.size();
            while(n>0){
                cur = q.front();
                q.pop();
                if(cur->left!=nullptr) q.push(cur->left);
                if(cur->right!=nullptr) q.push(cur->right);
                n--;
            }
        }
        return depth;
    }
};
