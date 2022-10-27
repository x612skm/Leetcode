class Solution {
private:
    void erase(vector<vector<char>>& grid, int i, int j){
        //cecking the edge case conditons
        if(i>=grid.size() or i < 0 or j>=grid[0].size() or j<0 or grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        erase(grid, i+1, j);
        erase(grid, i-1, j);
        erase(grid, i, j+1);
        erase(grid, i, j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n =m ? grid[0].size() : n;
        int island = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    island++;
                    erase(grid,i,j);
                }
            }
        }
        return island;
    }
};