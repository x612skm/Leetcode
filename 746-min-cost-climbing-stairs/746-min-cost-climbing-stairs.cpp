class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost, int n){
        if(n<0) return 0;
        if(n==0 || n==1) return cost[n];
        if(t[n] != -1) return t[n];
        
        return t[n] = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
        int n = cost.size();
        //int t[n];
        return min(solve(cost, n-1), solve(cost, n-2));
    }
};