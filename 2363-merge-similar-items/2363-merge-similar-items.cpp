
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        //this question has a clear base regarding mapping their values with the wieght sum
        //so here we do the operaition using a hashmap
        //key value pairing
        
        map<int,int>mp; //unordered_map does not sort the things that why it is req.
        //inserting into the map
        //map is used when you want something in ordered rateher than the unordered
        //map is used here coz of the demanding situation of key value with weight
        for(auto i : items1) 
            mp[i[0]] += i[1];
        
        for(auto i : items2) 
            mp[i[0]] += i[1];
        
        //to store it from the map we need a vector
        vector<vector<int>> v;
        
        for(auto i:mp)
            v.push_back({i.first, i.second}); //{} brackets are used for the 2D
            
        return v;
    }
};