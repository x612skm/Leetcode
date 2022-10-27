class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto it = products.begin();
        sort(it, products.end());
        vector<vector<string>> result;
        string curr = "";
        
        for(auto& c:searchWord){
            curr += c;
            vector<string>suggested;
            it = lower_bound(it, products.end(), curr); //search as per the word
            
            for(int i=0; i<3 and it+i != products.end(); i++){
                string &s = *(it+i);
                if(s.find(curr)) break;
                suggested.push_back(s);
            }
            result.push_back(suggested);
        }
        return result;
    }
};