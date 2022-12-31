class Solution {
private:
    //we will dfs here
    int dfs(vector<vector<int>>& grid, int i, int j){
        //checking the base case
        if(i<0 or j<0 or i>=grid.size() or j>= grid[0].size() or grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        
        int area = 1;
        
        area += dfs(grid, i-1, j);
        area += dfs(grid, i+1, j);
        area += dfs(grid, i, j-1);
        area += dfs(grid, i, j+1);
        
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int area = 0;
        for(auto i=0; i<grid.size(); i++){
            for(auto j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    area = dfs(grid, i, j);
                    maxarea = max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};