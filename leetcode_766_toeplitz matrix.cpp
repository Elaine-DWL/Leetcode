#include <iostream>

using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        if(m*n==m || m*n==n) return true;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] != matrix[i-1][j-1]) return false;
            }

        }
        return true;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
