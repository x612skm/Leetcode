class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        //sort(tasks.begin(), tasks.end());
        unordered_map<int, int> mp;
        for(auto i:tasks){
            mp[i]++;
        }
        //cout<<mp[4];
        int count = 0;
        for(auto it:mp){
            if(it.second == 1)
                return -1;
            else if(it.second%3 == 0)
                count += it.second/3;
            else {
                count += it.second/3 + 1;
            }
        }
        if(count)
           return count;
        else
            return -1;
    }
};