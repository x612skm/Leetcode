class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //return vector
        vector<int>ans;
        //make a map for the frequnecy
        unordered_map<int, int>mp;
        for(auto& it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > mp.size() - k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return ans;
    }
};