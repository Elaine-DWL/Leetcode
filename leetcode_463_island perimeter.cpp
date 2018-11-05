// 方法一  暴力
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();// m行 n列
        int sum=0;
        for(int i=0; i<m; i++){
            grid[i].push_back(0);
            grid[i].insert(grid[i].begin(), 0);
        }
        grid.insert(grid.begin(), vector<int>(n+2, 0));
        grid.push_back(vector<int>(n+2, 0));
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(grid[i][j]==1){
                    if(grid[i-1][j]==0) sum++;
                    if(grid[i+1][j]==0) sum++;
                    if(grid[i][j-1]==0) sum++;
                    if(grid[i][j+1]==0) sum++;
                }
            }
        }
        return sum;
    }
};