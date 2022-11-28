class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = -1;//because we will count the zeoth term again
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>&a , vector<int>&b)
             {
                 return a[1] < b[1];
             });
        
        vector<int>first = intervals[0];
        for(auto it:intervals){
            if(first[1] > it[0])
                ans++;
            else
                first = it;
        }
        return ans;
    }
};