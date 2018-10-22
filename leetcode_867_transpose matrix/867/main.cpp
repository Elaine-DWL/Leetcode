#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m=A[0].size(), n=A.size();
        if(m*n==1)return A;
        vector<vector<int>> res(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res[i][j] = A[j][i];
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
