class Solution {
public:
    string cur;
    vector<string>res;
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
        Trie() {
            root=new Node;
        }
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
        bool search(string word) {
            Node* cur=root;
            for(int i=0;i<word.size();i++){
                cur=Find(cur,word[i]);
                if(!cur) return false;
                if(i+1==word.size()&&!cur->leaf) return false;
            }
            return true;
        }
        bool startsWith(string prefix) {
            Node* cur=root;
            for(int i=0;i<prefix.size();i++){
                cur=Find(cur,prefix[i]);
                if(!cur) return false;
            }
            return true;
        }
    };
    void DFS(vector<vector<char>>&board,Trie::Node* T,int x,int y,vector<vector<bool>>&visited){
        cur+=T->data;
        visited[x][y]=true;
        if(T->leaf){
            res.push_back(cur);
            T->leaf=false;
        }
        for(auto i:T->next){
            if(x!=0&&!visited[x-1][y]&&board[x-1][y]==i->data){
                DFS(board,i,x-1,y,visited);
                cur.pop_back();
                visited[x-1][y]=false;
            }
            if(x+1!=board.size()&&!visited[x+1][y]&&board[x+1][y]==i->data){
                DFS(board,i,x+1,y,visited);
                cur.pop_back();
                visited[x+1][y]=false;
            }
            if(y!=0&&!visited[x][y-1]&&board[x][y-1]==i->data){
                DFS(board,i,x,y-1,visited);
                cur.pop_back();
                visited[x][y-1]=false;
            }
            if(y+1!=board[0].size()&&!visited[x][y+1]&&board[x][y+1]==i->data){
                DFS(board,i,x,y+1,visited);
                cur.pop_back();
                visited[x][y+1]=false;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty()||board[0].empty()||words.empty()) return res;
        Trie T;
        for(string word:words) T.insert(word);
        for(auto x:T.root->next) for(int i=0;i<board.size();i++) for(int j=0;j<board[0].size();j++) if(x->data==board[i][j]){
            vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
            DFS(board,x,i,j,visited);
            cur.pop_back();
        }
        return res;
    }
};
