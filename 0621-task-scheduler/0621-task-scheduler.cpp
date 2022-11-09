class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>mp;
        //we will have the tasks frequenecy
        for(auto& t : tasks){
            mp[t]++;
        }
        
        priority_queue<int>pq;
        for(auto& count : mp){
            pq.push(count.second);//push the frequency inside
        }
        
        int allTime = 0;
        int cycle = n+1;//we have to add 1 everytime to the cycle
        while(!pq.empty()){
            int time = 0;
            vector<int>temp;
            for(int i=0; i<cycle; ++i){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for(auto cnt : temp)
                if(--cnt)
                    pq.push(cnt);
            
            if(!pq.empty())
                allTime += cycle;
            else
                allTime += time;
        }
        
        return allTime;
    }
};