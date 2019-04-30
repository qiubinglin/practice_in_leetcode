
方法1：
c++
(from jianchao-li)
class TrieNode {
public:
    bool wordend;
    TrieNode* children[26];
    TrieNode() {
        wordend = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
       root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        
        for(auto &c : word){
            if(!node->children[c - 'a']){
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->wordend = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return _search(word.c_str(), root);
    }
private:
    TrieNode* root;
    
    bool _search(const char* word, TrieNode* node) {
        for(int i = 0; word[i] && node; ++i){
            if(word[i] != '.'){
                node = node->children[word[i] - 'a'];
            }
            else{
                TrieNode *tmp = node;
                for(int j = 0; j < 26; ++j){
                    node = tmp->children[j];
                    if(_search(word+i+1, node)){
                        return true;
                    }
                }
            }
        }
        return node && node->wordend;
    }
};