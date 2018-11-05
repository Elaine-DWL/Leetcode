#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r0=nums.size();
        int c0=nums[0].size();
        if(r*c != r0*c0) return nums;
        vector<vector<int>> res(r, vector<int>(c, 0));
//        for(int i=0; i<r; i++){
//            for(int j=0; j<c; j++){
//                int t = i*r+j;
//                res[i][j] = nums[t/c][t-(t/c)*r-1]);
//            }
//        }
        for(int i=0; i<r0; i++){
            for(int j=0; j<c0; j++){
                int k=i*c0+j;
                res[k/c][k%c] = nums[i][j];
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





