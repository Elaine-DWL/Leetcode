class Solution {
public:
    // 1~n能生成多少棵不同结构的BST
    int numTrees(int n) {
        vector<int> f(1000, 0);
        f[0]=1;f[1]=1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                f[i] += f[j]*f[i-1-j];
            }
        }
        return f[n];
    }
};