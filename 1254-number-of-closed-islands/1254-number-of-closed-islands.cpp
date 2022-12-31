class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j){
        //checking for the out-of bounds conditions
        
        if(i<0 or j<0 or i>= grid.size() or j>= grid[0].size() or grid[i][j] != 0)
            return;
        grid[i][j] = -1;
        
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        //mark all the zeroes that are connected to the border as -1
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if((i==0 or j==0 or i==grid.size()-1 or j==grid[0].size()-1) and grid[i][j] == 0)
                    dfs(grid, i, j);
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                //corner case
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};