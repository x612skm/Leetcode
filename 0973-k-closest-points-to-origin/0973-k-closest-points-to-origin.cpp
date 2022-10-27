class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans(k);
        priority_queue<vector<int>> maxheap;
        
        for(auto& p : points){
            int x = p[0]; int y = p[1];
            int total = x*x + y*y;
            
            maxheap.push({total, x, y});
            
            if(maxheap.size()>k)
                maxheap.pop();
        }
        
        for(int i=0; i<k; i++){
            vector<int> close = maxheap.top();
            maxheap.pop();
            ans[i] = {close[1], close[2]};
        }
        return ans;
    }
};