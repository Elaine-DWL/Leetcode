#include <iostream>

using namespace std;
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if(m<3 || n<3) return 0;
        int sum=0;
        for(int i=0; i<=m-3; i++){
            for(int j=0; j<=n-3;j++){
                int t = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                if(grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]==t //第二行
                   && grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]==t //第三行
                   && grid[i][j]+grid[i+1][j]+grid[i+2][j]==t //第一列
                   && grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]==t//第二列
                   && grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]==t//第三列
                   && grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]==t// 对角线
                   && grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]==t){// 对角线
                        sum++;
                   }
            }
        }
        return sum;
    }
};
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
