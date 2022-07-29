class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>mp;
        char ans; //to store the ans
        for(auto it:s){
            if(mp.find(it) != mp.end()){
                ans=it; //the char which comes first two times will be the ans
                break;
                
            }
            mp[it]++;
        }
        return ans;
    }
};