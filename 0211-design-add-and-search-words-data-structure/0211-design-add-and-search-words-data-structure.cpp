class TrieNode{
public:
    TrieNode* children[26];
    bool isword;
    
    TrieNode() {
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isword = false;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        int curr = 0;
        for(int i=0; i<word.size(); i++){
            curr = word[i] - 'a'; //returning to the int by subtracting the ascii value
            if(node->children[curr] == NULL)
                node->children[curr] = new TrieNode();
            
            node=node->children[curr];
        }
        node->isword = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return searchinNode(word,0,node);
    }
private:
    TrieNode* root;
    bool searchinNode(string&word, int i, TrieNode* node){
        if(node == NULL)
            return false;
        
        if(i == word.size())
            return node->isword;
        
        if(word[i] != '.')
            return searchinNode(word,i+1,node->children[word[i] - 'a']);
        
        for(int j=0; j<26; j++){
           if(searchinNode(word,i+1, node->children[j])){
                    return true;
           }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */