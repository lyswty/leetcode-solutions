class Trie {
public:
    class Node{
    public:
        bool leaf;
        char data;
        vector<Node*> next;
        Node(){}
        Node(char i):data(i),leaf(false){}
    };
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root=new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur=root;
        for(int i=0;i<word.size();i++){
            cur=Insert(cur,word[i]);
            if(i+1==word.size()) cur->leaf=true;
        }
    }
        
    Node* Insert(Node* T,char x){
        Node* cur=Find(T,x);
        if(!cur){
            cur=new Node(x);
            T->next.push_back(cur);
        }
        return cur;
    }
    Node* Find(Node* T,char x){
        for(Node* i:T->next) if(i->data==x) return i;
        return NULL;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur=root;
        for(int i=0;i<word.size();i++){
            cur=Find(cur,word[i]);
            if(!cur) return false;
            if(i+1==word.size()&&!cur->leaf) return false;
        }
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur=root;
        for(int i=0;i<prefix.size();i++){
            cur=Find(cur,prefix[i]);
            if(!cur) return false;
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
