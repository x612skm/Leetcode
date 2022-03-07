class Solution {
public:
    int t[40];
    int solve(int n){
        if(n == 0 || n == 1) return n;
        if(n == 2) return 1;
        if(t[n] != -1) return t[n];
        
        return t[n] = solve(n-1) + solve(n-2) + solve(n-3);
    }
    int tribonacci(int n) {
       memset(t,-1,sizeof(t));
        return solve(n);
    }
};