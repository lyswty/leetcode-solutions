class WordDictionary {
public:
    typedef struct Node{
        char data;
        bool leaf;
        vector<Node*>next;
        Node():leaf(false){}
    }*Trie;
    Trie root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new Node;
    }
    Trie Find(Trie T,char x){
        for(auto res:T->next) if(res->data==x) return res;
        return NULL;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto ptr=root;
        for(int i=0;i<word.size();i++){
            auto cur=Find(ptr,word[i]);
            if(cur) ptr=cur;
            else{
                Trie p=new Node;
                p->data=word[i];
                ptr->next.push_back(p);
                ptr=p;
            }
            if(i+1==word.size()) ptr->leaf=true;
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return DFS(word,0,root);
    }
    bool DFS(string word,int i,Trie T){
        if(i==word.size()&&T->leaf) return true;
        for(auto x:T->next) if((word[i]=='.'||x->data==word[i])&&DFS(word,i+1,x)) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
