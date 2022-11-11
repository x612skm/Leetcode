class Solution {
//making a constructor for comparator function
private:
    struct comp{
        bool operator()(pair<int,string>&lhs, pair<int,string>&rhs){
            if(lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //we will use a map and a heap which is basically a min heap
        unordered_map<string, int>mp;
        for(auto& word : words){
            ++mp[word];
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp>pq;
        //inside the pq it will sort acc to the comparator rwritten
        for(auto& it:mp)
            pq.emplace(it.second, it.first);
        
        vector<string>res;
        
        while(k-->0 and !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};