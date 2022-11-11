class Solution {
//making a constructor for comparator function
private:
    struct comp{
        //if freq not equal sort accoring to the freq or lexiographical sorting
        bool operator()(pair<int,string>&lhs, pair<int,string>&rhs){
            if(lhs.first != rhs.first)
                return lhs.first < rhs.first;//if the frequency is not same then acc to freq
            return lhs.second > rhs.second;//if the frequency is same then lexiographical
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //we will use a map and a heap which is basically a min heap
        unordered_map<string, int>mp;
        for(auto& word : words){
            ++mp[word];
        }
        //minheap becasue we have to use a comparator fn to all the items
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp>pq;
        //inside the pq it will sort acc to the comparator rwritten
        for(auto& it:mp)
            pq.emplace(it.second, it.first);
        
        vector<string>res;
        //insert for the k elements template for the heap questions
        while(k-->0 and !pq.empty()){
            res.push_back(pq.top().second);
            //first elements will be automatically sorted using lexiographical order
            pq.pop();
        }
        return res;
    }
};