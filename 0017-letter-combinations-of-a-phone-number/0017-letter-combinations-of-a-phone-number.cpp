class Solution {
    //[2,3]
private:
    void dfs(string& digits, int index, vector<string>&result, string& curr, unordered_map<char, string>&mp){
        
        if(index == digits.size()){
            result.push_back(curr);
            return;
        }
        
        //classical backtrackign approach
        string str = mp[digits[index]];
        
        for(int i=0; i<str.size(); i++){
            curr.push_back(str[i]);
            dfs(digits, index+1, result, curr , mp);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        //we make a map dictionary
        unordered_map<char,string>mp{{'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        //no need to add it passing it via reference int index;
        string curr = "";
        vector<string> result;
        
        
        dfs(digits,0, result, curr, mp);
        return result;
        
    }
};