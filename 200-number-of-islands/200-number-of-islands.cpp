class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int island = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1')
                {
                    island++;
                    eraseIsland(grid,i,j);
                }
            }
        }
        return island;
    }
    
private:
    void eraseIsland(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i==m || i < 0 || j == n || j < 0 || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        eraseIsland(grid, i-1, j);
        eraseIsland(grid, i+1, j);
        eraseIsland(grid, i, j-1);
        eraseIsland(grid, i, j+1);

    }
};