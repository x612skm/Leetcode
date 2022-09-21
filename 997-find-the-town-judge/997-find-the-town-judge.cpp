class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //using map data structure
        if(n==1) return 1;
        unordered_map<int,int>first;
        unordered_map<int,int>second;
        
        for(int i=0; i< trust.size(); i++){
            first[trust[i][0]]++;
        }
        
        for(int i=0; i<trust.size(); i++){
            second[trust[i][1]]++;
            
        }
        
        for(int i=0; i<=n; i++){
            if(first[i] == 0 and second[i] == n-1)
                return i;
        }
        return -1;
    }
};