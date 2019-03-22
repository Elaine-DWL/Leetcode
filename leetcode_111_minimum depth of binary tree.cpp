class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int l=minDepth(root->left), r=minDepth(root->right);
        // return 1+min(l, r);// 这样是错误的 当某个结点仅有一个子树这样写会认为该结点的高度为1   而实际上路径长度指的是到叶子结点的距离，
        return 1 + (min(l, r)==0?max(l,r):min(l, r)); 
    }
};