class Solution {
private:
    void dfs(vector<vector<int>>& a, int i, int j){
        //make the 1 as 0 so that border island will vanish
        //check for the out of bound conditons
        if(i >= 0 && i <= a.size() - 1 && j >= 0 && j <= a[i].size() - 1 && a[i][j] == 1) {
            a[i][j] = 0;
            dfs(a, i + 1, j);
            dfs(a, i - 1, j);
            dfs(a, i, j + 1);
            dfs(a, i, j - 1);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 or j==0 or i == grid.size()-1 or j == grid[i].size()-1)
                    dfs(grid, i, j);
            }
        }
        
        int result = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1)
                    result++;
            }
        }
        return result;
    }
};