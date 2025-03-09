class Trie {
public: 
    vector<Trie*> children;
    bool eow = false;

    Trie() {
        children.resize(26,nullptr);
    }
    
    void insert(string word) {
        Trie* root = this;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            int idx = ch - 'a';
            if (root->children[idx] == nullptr){
                root->children[idx] = new Trie();
            }
            root = root->children[idx];
        }   
        root->eow = true; 
    }
    
    bool search(string word) {
        Trie* root = this;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if (root->children[idx] == nullptr){
                return false;
            }
            root = root->children[idx];
        }
        return root->eow;
    }
    
    bool startsWith(string prefix) {
        Trie* root = this;
        for(int i = 0; i < prefix.size();i++){
            int idx = prefix[i] - 'a';
            if (root->children[idx] == nullptr){
                return false;
            }
            root = root->children[idx];
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