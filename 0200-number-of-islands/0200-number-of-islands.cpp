class Solution {
private:
    void eraseIsland(vector<vector<char>>&grid, int i, int j){
        //both i and j are matrix sizes
        //checking the base or outline condtn for dfs
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size() or grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        eraseIsland(grid, i-1, j);
        eraseIsland(grid,i+1,j);
        eraseIsland(grid,i,j-1);
        eraseIsland(grid,i,j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        //this question tends to be the graph coloring problem
        //we will use dfs for it
        //wherever we find 0 we make the adjacent to 0 
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int island = 0;
        //searching in the matrix
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(grid[i][j] == '1')
                {
                    island++;
                    eraseIsland(grid,i,j);
                }
            }
        }
        return island;
    }
};