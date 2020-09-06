
考察储存数据的复用

方法1
派生树结构
c++
(from cxq1992)
class TrieNode{
public:
    char content;
    bool isEnd;
    int shared;
    vector<TrieNode*> children;
    
    TrieNode(): content(' '), isEnd(false), shared(0) {}
    TrieNode(char ch): content(ch), isEnd(false), shared(0) {}
    
    TrieNode* subNode(char c){
        if(!children.empty()){
            for(auto &child : children){
                if(child->content == c){
                    return child;
                }
            }
        }
        return NULL;
    }
    
    ~TrieNode(){
        for(auto &p : children){
            delete p;
        }
    }
};

class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(search(word)){
            return;
        }
        
        TrieNode *curr = root;
        for(auto &c : word){
            TrieNode *tmp = curr->subNode(c);
            if(tmp == NULL){
                tmp = new TrieNode(c);
                curr->children.push_back(tmp);
            }
            ++(curr->shared);
            curr = tmp;
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        for(auto &c : word){
            curr = curr->subNode(c);
            if(curr == NULL){
                return false;
            }
        }
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(auto &c : prefix){
            curr = curr->subNode(c);
            if(curr == NULL){
                return false;
            }
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
