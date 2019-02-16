// leetcode 
// 方法一  递归
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
    // 返回二叉树的中序遍历
    void inorder(TreeNode *root, vector<int> &nums){
        if(root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        inorder(root, res);
        return res;
    }
};


// 非递归方法 用堆栈来实现
class Solution {
public:
    // 中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        do{
            while(cur!=nullptr){
                s.push(cur);
                cur = cur->left;
            }
            TreeNode *t = s.top();
            res.push_back(t->val);
            s.pop();
            cur = t->right;
        }while(!s.empty() || cur!=nullptr); // 注意这里的循环条件
        return res;
    }
};
vector<int> inorderTraversal(TreeNode* root){
	TreeNode* cur = root;
	vector<int> res;
	stack<int> s;
	while(cur!=nullptr && !s.empty()){
		while(cur!=nullptr){
			s.push(cur);
			cur = cur->left;
		}
		TreeNode* t = s.top();
		s.pop();
		res.push_back(t->val);
		cur = cur->right;
	}
	return res;
}