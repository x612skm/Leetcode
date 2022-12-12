class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //from the find all the anagrams of the string 
        if(s1.size() > s2.size()) return {};
        bool flag = false;
        unordered_map<int, int>s1map;
        unordered_map<int, int>s2map;
        
        for(int i=0; i<s1.size(); i++){
            s1map[s1[i]]++;
            s2map[s2[i]]++;
        }
        if(s1map == s2map) return true;
        int end = 0;
        
        for(int i=s1.size(); i<s2.size(); i++){
             
            s2map[s2[i]]++;
            s2map[s2[end]]--;
            
            if(s2map[s2[end]] == 0)
                s2map.erase(s2[end]);
             
            if(s1map == s2map)
                flag =  true;
            
            end++;
        }
        return flag;
    }
};