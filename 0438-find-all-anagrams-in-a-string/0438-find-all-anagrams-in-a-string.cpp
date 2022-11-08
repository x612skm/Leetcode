class Solution {
private:
    //https://leetcode.com/problems/valid-anagram/ lc 242
    /*
     bool isAnagram(string s, string t) {
      if(s.size() != t.size()) return false; 
        unordered_map<char,int>mp;
        int n = s.size();
        for(int i=0; i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it : mp)
            if(it.second) return false;
        return true;
    }
    */
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        unordered_map<int, int> pmap;
        unordered_map<int, int> smap;
        
        //cehecking for the zero case 
        for(int i=0; i<p.size(); i++){
            smap[s[i]]++;
            pmap[p[i]]++;
        }
        if(smap == pmap) ans.push_back(0);
        
        //checking for the rest cases
        int end = 0;
        //smap e,b,a,b,a,c,d
        //smap => c b a s=> e , c--. end=1, b , b-- , aeb, end==2, eba, end =3, aebb 
        //abb, end=4, aba, end = 5, bac end=6, smap == pmap ans=>6 return 6; acd end = 7
        for(int i=p.size(); i<s.size(); ++i){
            smap[s[i]]++;
            smap[s[end]]--;
            
            if(smap[s[end]] == 0)
                smap.erase(s[end]);
            
            end++;
            
            if(smap == pmap)
                ans.push_back(end);
            //end++;
        }
        return ans;
    }
};