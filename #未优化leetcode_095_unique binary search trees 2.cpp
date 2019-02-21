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
    // 生成包含结点 start~end 的所有可能结构的BST
    vector<TreeNode *> generateSubtrees(int start, int end){
        vector<TreeNode *> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }
        if(start == end){
            // TreeNode t(start);
            TreeNode *root = new TreeNode(start);
            res.push_back(root);
            return res;
        }
        for(int i=start; i<=end; i++){ // 以i为根结点
            vector<TreeNode *> left = generateSubtrees(start, i-1);
            vector<TreeNode *> right = generateSubtrees(i+1, end);
            for(auto l:left){
                for(auto r:right){
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    // 生成包含1~n的所有可能结构的BST
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode *>();
        return generateSubtrees(1, n);
    }
};