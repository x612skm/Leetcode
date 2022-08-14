class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result , word;
        while(ss>>word){
            if(word != " ")
                result = word + " " + result;
        }
        result.pop_back();
       
        return result;
    }
};