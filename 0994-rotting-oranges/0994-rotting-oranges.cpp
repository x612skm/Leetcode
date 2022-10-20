class Solution {
public:
    vector<int>cordinates = {0,1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        //making a queue
        queue<pair<int,int>>visited;
        
        int rowsize = grid.size();
        int colsize = grid[0].size();
        //for calculating the 1s
        int fresh = 0;
        
        for(int row = 0; row<rowsize; row++){
            for(int col=0; col<colsize; col++){
                if(grid[row][col] == 2)
                    visited.emplace(row,col);
                else if(grid[row][col] == 1)
                    fresh++; //cout<<fresh<<endl;
            }
        }
        //making the time as -1 since we step in to first '2' it will become 0
        int time = -1;
        //caling the bfs fn
        while(!visited.empty()){
            int size = visited.size();
            while(size--){
            auto[row,col] = visited.front();
            visited.pop();
            for(int i=0; i<4; i++){
                int neigh_row = row + cordinates[i];
                int neigh_col = col + cordinates[i+1];
                
                if(neigh_row<0 or neigh_row == rowsize or neigh_col <0 or neigh_col == colsize or grid[neigh_row][neigh_col] != 1)
                    continue;
                grid[neigh_row][neigh_col] = 2;
                visited.emplace(neigh_row, neigh_col);
                fresh--;
            }
            }
            time++;
            cout<<time;
        }
        
        if(fresh > 0) return -1;
        if(time == -1) return 0;
        return time;
    }
};