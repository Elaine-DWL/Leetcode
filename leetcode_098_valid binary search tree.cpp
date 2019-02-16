/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 方法一 递归
class Solution {
public:
    // 判断一棵树是否为二叉查找树 BST
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
        
    }
    bool isValid(TreeNode *root, TreeNode *rminNode, TreeNode *lmaxNode){
        if(!root) return true;
        if(rminNode && root->val >= rminNode->val) return false;
        if(lmaxNode && root->val <= lmaxNode->val) return false;
        return isValid(root->left, root, lmaxNode) && isValid(root->right, rminNode, root);
    }
};