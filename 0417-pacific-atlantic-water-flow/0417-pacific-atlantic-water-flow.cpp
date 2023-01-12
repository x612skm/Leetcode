class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col, int prevheight){
        
        //checking for the out of bound condiotns
        int m = heights.size();
        int n= heights[0].size();
        //checking the out of bound conditons
        if(row < 0 or col < 0 or row >= m or col >= n or visited[row][col] or heights[row][col] < prevheight)
            return;
        
        visited[row][col] = true;
        
        dfs(heights, visited, row-1, col, heights[row][col]);
        dfs(heights, visited, row+1, col, heights[row][col]);
        dfs(heights, visited, row, col-1, heights[row][col]);
        dfs(heights, visited, row, col+1, heights[row][col]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //we have to search for both the layers of atlantic and pacific ocean
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> atl( row , vector<bool> (col, false));
        //rows for pacific and atlantic
        for(int r=0; r<row; ++r){
            dfs(heights, pac, r, 0, heights[r][0]);
            dfs(heights, atl, r, col-1, heights[r][col-1]);
        }
        //col for pacific and atlantic
        for(int c=0; c<col; ++c){
            dfs(heights, pac, 0, c, heights[0][c]);
            dfs(heights, atl, row-1, c, heights[row-1][c]);
        }
        
        vector<vector<int>> result;
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(pac[i][j] and atl[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};