class Solution {
    public String mergeAlternately(String word1, String word2) {
        //it is similar to c++ string = ""
        StringBuilder result = new StringBuilder();
        
        int iter = 0;
        //will iterate one by one in each word
        while(iter < word1.length() || iter < word2.length()){
            if(iter < word1.length()){
                result.append(word1.charAt(iter));
            }
            if(iter < word2.length()){
                result.append(word2.charAt(iter));
            }
                
            iter++;
        }
        return result.toString();
    }
}