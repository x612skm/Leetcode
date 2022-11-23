class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n, INT_MAX);
        //mark the source as 0
        //using bellman ford algorithm
        distance[src] = 0;
        
        for(int stops = 0; stops <= k; stops++){
            vector<int>temp = distance;
            for(auto& flight : flights){
                int s = flight[0]; int d = flight[1]; int p =flight[2];
                
                if(distance[s] == INT_MAX)
                    continue;
                if(temp[d] > distance[s] + p)
                    temp[d] = distance[s] + p;
            }
            distance = temp;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};