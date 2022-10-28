class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>v(60,0);
        int count = 0;
        
        for(int i=0; i<time.size(); i++){
            int a = time[i] % 60;
            if(a == 0)
                count+=v[0];
            else
                count+=v[60-a];
            
            v[a]++;
        }
        return count;
    }
};