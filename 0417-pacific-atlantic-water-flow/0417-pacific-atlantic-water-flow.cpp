class Solution {
private:
    //same template used of FLood fill just add the visited component
    void dfs(vector<vector<int>>&heights, vector<vector<bool>>&visited, int row, int col, int prevheight){
        int m = heights.size();
        int n= heights[0].size();
        //checking the out of bound conditons
        if(row < 0 or col < 0 or row >= m or col >= n or visited[row][col] or heights[row][col] < prevheight)
            return;
        
        visited[row][col] = true;
        
        //check for the directions of the cells using the condiotns
        dfs(heights, visited, row-1, col, heights[row][col]);
        dfs(heights, visited, row+1, col, heights[row][col]);
        dfs(heights, visited, row, col-1, heights[row][col]);
        dfs(heights, visited, row, col+1, heights[row][col]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        //checking the adjacent rows and cols to the pacfic and atlantic ocean
        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> atl( row , vector<bool> (col, false));
        
        //there will be one dfs call for pacific and one for atlantic
        //check for the adjacnet rows for the pacific and atlantic
        for(int r = 0; r<row; ++r){
            dfs(heights, pac, r, 0, heights[r][0]);
            dfs(heights, atl, r, col-1, heights[r][col-1]);
        }
        //check for the adjacent cols for the pacific and atlantic
        for(int c=0; c<col; ++c){
            dfs(heights, pac, 0, c, heights[0][c]);
            dfs(heights, atl, row-1, c, heights[row-1][c]);
        }
        //append the result which cells are true and satifies the condition
       vector<vector<int>>result;
        for(int r=0; r<row; ++r){
            for(int c=0; c<col; ++c){
                if(pac[r][c] and atl[r][c])
                    result.push_back({r,c});
            }
        }
        //return the result
        return result;
    }
};