class Solution {
public:
    struct node{
        node* children[26];
        bool empty;
        node():children(),empty(true){}
        ~node(){
            for(int i=0;i<26;i++) delete children[i];
        }
    };
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        auto T=new node();
        for(auto &word:words){
            auto cur=T;
            for(char x:word){
                int idx=x-'a';
                if(!cur->children[idx]) cur->children[idx]=new node();
                cur=cur->children[idx];
            }
            cur->empty=false;
        }
        vector<string>res;
        for(auto &word:words) if(judge(word,0,T)) res.emplace_back(word);
        delete T;
        return res;
    }
    bool judge(string &word,int cnt,node* T){
        auto cur=T;
        for(int i=0;i<word.size();i++){
            cur=cur->children[word[i]-'a'];
            if(!cur) return false;
            if(!cur->empty){
                if(i+1==word.size()) return cnt>0;
                string remain=word.substr(i+1);
                if(judge(remain,cnt+1,T)) return true;
            }
        }
        return false;
    }
};
