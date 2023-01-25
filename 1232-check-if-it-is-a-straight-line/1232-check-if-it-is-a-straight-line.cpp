class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //equation of a straight line 
        //y = mx + c
        
        int xd = coordinates[1][0] - coordinates[0][0];
        int yd = coordinates[1][1] - coordinates[0][1];
        
        for(auto i=2; i<coordinates.size(); i++){
            int xs = coordinates[i][0] - coordinates[0][0];
            int ys = coordinates[i][1] - coordinates[0][1];
            
            if(xs*yd != xd*ys)
                return false;
        }
        return true;
    }
};