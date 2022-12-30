class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() or j >= grid[0].size() or i < 0 or j <0 or grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int island = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1')
                {
                    island++;
                    dfs(grid, i, j);
                }
            }
        }
        return island;
    }
};