class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        string s = "";

        int i=0, j=0;
        
        while(i<n1 && j<n2)
        {
            //alternative insertion
            s += word1[i++];
            s += word2[j++];
        }    
        
        //edge cases
        //if the word exceeds
        
        while(i<n1)
            s += word1[i++];
        
        while(j<n2)
            s += word2[j++];
        
        
        return s;
    }
};