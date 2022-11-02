class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        
        vector<vector<int>>result;
        vector<int> inter;
        
        //inter.push_back(intervals[0][0]);
        inter = intervals[0];
        //[1,4] => inter
        //inter = intervals[0];
        result.push_back(inter);
        //inter.push_back(intervals[0]);
        for(auto i = 1; i<intervals.size(); i++){
            //4 => inter[1] 
            if(inter[1] >= intervals[i][0]){
                //inter.push_back(intervals[i+1][1]);
                inter[1] = max(inter[1], intervals[i][1]);
                result.pop_back();
                result.push_back(inter);
            }
            //intervals
            
            else{
                //inter.clear();
                inter = intervals[i];
                result.push_back(inter);
            }
            //result.push_back(inter);
        }
        return result;
    }
};