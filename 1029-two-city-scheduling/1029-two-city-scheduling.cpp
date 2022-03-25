class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // a refund amount for the minimum cost
        vector<int>refund;
        int n = costs.size()/2;
        int min_cost = 0;
        
        for(vector<int>cost : costs){
            min_cost += cost[0];
            refund.push_back(cost[1] - cost[0]);
        }
        
        //sort to get the array negatives
        sort(refund.begin(), refund.end());
        
        for(int i=0; i<n; i++){
            min_cost += refund[i];
        }
        return min_cost;
    }
};