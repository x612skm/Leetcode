class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        for(char& ins : instructions){
            if(ins == 'R')
                i = (i+1) % 4; //moving towards right 
            else if(ins == 'L')
                i = (i+3) % 4; //moving left = right * 3
            else
                x += dir[i][0], y += dir[i][1];
        }
        return x == 0 and y == 0 or i > 0;
    }
};