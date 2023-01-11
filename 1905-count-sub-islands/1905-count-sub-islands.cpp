class Solution {
private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        //condtions for the out of bound 
        if(i<0 or j<0 or i==grid1.size() or j==grid1[0].size() or grid2[i][j] == 0)
            return true;
        
        if(grid1[i][j] == 0) return false;
        
        grid2[i][j] = 0;
        
        bool b1 = dfs(grid1, grid2, i-1, j);
        bool b2 = dfs(grid1, grid2, i+1, j);
        bool b3 = dfs(grid1, grid2, i, j-1);
        bool b4 = dfs(grid1, grid2, i, j+1);
        
        return b1&b2&b3&b4;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //we have to found the 1s in the grid1 from grid2
        //when finding the sub island we have to find the & operator
        int count = 0;
        for(int i=0; i<grid1.size(); i++){
            for(int j=0; j<grid1[0].size(); j++){
                if(grid2[i][j])
                    count+= dfs(grid1, grid2, i, j);
            }
        }
        return count;
    }
};