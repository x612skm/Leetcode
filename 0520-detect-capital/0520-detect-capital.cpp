class Solution {
public:
    bool detectCapitalUse(string word) {
        for (int i = 1; i < word.size(); i++) {
            if ((word[1] >= 'A' && word[1] <= 'Z') != (word[i] >= 'A' && word[i] <= 'Z') || (word[0] >= 'a' && word[0] <= 'z' && (word[i] >= 'A' && word[i] <= 'Z'))) {
                return false;
            }
        }
        return true;
    }
};
