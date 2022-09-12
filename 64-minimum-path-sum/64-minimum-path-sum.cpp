class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();//row
        int n = grid[0].size();//col
        //m is for the row and n is for the col
        //m 
        for(int i=1; i<m; i++)
            grid[i][0] += grid[i-1][0];
        //same for the cols
        for(int j=1; j<n; j++)
            grid[0][j] += grid[0][j-1];
        //for the diagonal
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        int res = grid[m-1][n-1];
        return res;
    }
};