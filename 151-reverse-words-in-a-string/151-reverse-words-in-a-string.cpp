class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        
        string result , word;
        cout<<result;
        while(ss>>word){
            if(word != " ")
                cout<<word;
                result = word + " " + result;
                
        }
        result.pop_back();
       
        return result;
    }
};