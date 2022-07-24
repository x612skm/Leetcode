class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        //make a counter
        int count = 0;
        //check for the grid[rowWisw] calling next row for the same
        for(int i=0; i<grid.size(); ++i)
            count += Function_call_negative_count(grid[i]);
        
        return count;
    }
    
private:
    int Function_call_negative_count(vector<int>gridRow){
    //this fn call is only for the row wise;
    
    //make a counter here 
    int count = 0;
    int first = 0, last = gridRow.size()-1;
    
    while(first <= last){
        //make a middle check for the same
        int mid = first + (last - first)/2; //to not make the overflow
        
        if(gridRow[mid] >= 0)
            first = mid + 1;
        
        else if(gridRow[mid] <= 0){
            count += last - mid + 1;
            last = mid -1;
        }
        
    }
    return count;
    }
};