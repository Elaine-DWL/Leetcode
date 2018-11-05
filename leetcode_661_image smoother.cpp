#include <iostream>
#include <>
using namespace std;
// 暴力求解
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size(), col = M[0].size();
        vector<vector<int>> res;
        int a[8]={0};
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                // 遍历9个坐标
                int cnt=0;//周围元素的个数
                int sum=0;//周围元素求和
                for(int k=i-1; k<= )

            }
        }

    }
};
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m=M.size(), n=M[0].size();
        vector<vector<int>> cnt(m+2, vector<int>(n+2, 1));//用于计数的矩阵，四周都是0，中间都是1

        for(int j=0; j<m+2; j++){// 将最左和最右两边变成0
            cnt[j][0] = 0;
            cnt[j][n+1] = 0;
        }
        for(int j=0; j<n+2; j++){// 将最上和最下两边变成0
            cnt[0][j] = 0;
            cnt[m+1][j] = 0;
        }
        vector<int> a(n+2, 0);// 将添加
        for(int i=0; i<m; i++){// 添加最左和最右的0
            M[i].push_back(0);
            M[i].insert(M[i].begin(), 0);
        }
        M.insert(M.begin(), a);//添加最上面的0
        M.push_back(a);//添加最下面的0
        vector<vector<int>> res(m, vector<int>(n));//用于存储结果的矩阵
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                int sum = M[i-1][j-1] + M[i-1][j] + M[i-1][j+1]
                            +M[i][j-1] + M[i][j+1]
                            +M[i+1][j-1] + M[i+1][j] + M[i+1][j+1];
                int num = cnt[i-1][j-1] + cnt[i-1][j] + cnt[i-1][j+1]
                            +cnt[i][j-1] + cnt[i][j+1]
                            +cnt[i+1][j-1] + cnt[i+1][j] + cnt[i+1][j+1];
                res[i][j] = sum/num;
            }
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
