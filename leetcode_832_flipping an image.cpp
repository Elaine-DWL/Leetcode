#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m=A.size(), n=A[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<=(n-1)/2; j++){
                // ÏÈÈ¡·´
//                A[i][j] = ~A[i][j];
//                A[i][n-1-j] = ~A[i][n-1-j];
                A[i][j] = A[i][j]==0?1:0;
                if(j ==n-1-j) break;
                A[i][n-1-j] = A[i][n-1-j]==0?1:0;
                swap(A[i][j], A[i][n-1-j]);
                //if(j+1 == n-1+j) break;
            }
        }
        return A;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
