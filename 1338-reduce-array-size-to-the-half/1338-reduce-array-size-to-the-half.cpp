class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        int res = 0;
        for(auto i : arr) mp[i]++;
        for(auto c : mp) pq.push(c.second);
        int count=0;
        
        while(count < arr.size()/2){
            count += pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};