class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        //sorting the letter logs files after splitting them from the digit files
        vector<string> digilogs, ans;
        vector<pair<string, string>> letlogs;
        
        //splitting and inserting the elements
        for(string& s : logs){
            int i = 0;
            while(s[i] != ' ') ++i;
            if(isalpha(s[i+1]))
                letlogs.emplace_back(s.substr(0,i), s.substr(i+1));
            else
                digilogs.push_back(s);
        }
        //sort the letterlogs acc to the questions condition
        sort(letlogs.begin(), letlogs.end(),
             [&](auto& a, auto& b){
            //sorting according to the pair of elements in a and b
            return a.second == b.second ? a.first < b. first : a.second < b.second;
        });
        
        //now concat the two
        for(auto &letter : letlogs)
            ans.push_back(letter.first + " " + letter.second);
        for(auto& digits : digilogs)
            ans.push_back(digits);
        
        return ans;
    }
};