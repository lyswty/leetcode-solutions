class Solution {
public:
    int res=-1,curcnt=0;
    void DFS(string& board,unordered_map<char,int>& cnt){
        if(board.empty()){
            if(res==-1||curcnt<res) res=curcnt;
            return;
        }
        for(int i=0;i<board.size();i++){
            int same;
            for(same=1;i+same<board.size()&&board[i+same]==board[i];same++);
            if(cnt[board[i]]>=3-same){
                cnt[board[i]]-=3-same;
                curcnt+=3-same;
                string cur=board.substr(0,i)+board.substr(i+same);
                remove(cur);
                DFS(cur,cnt);
                cnt[board[i]]+=3-same;
                curcnt-=3-same;
            }
            i+=same-1;
        }
    }
    void remove(string& s){
        for(int i=2;i<s.size();i++) if(s[i]==s[i-1]&&s[i]==s[i-2]){
            int j=i;
            for(j++;j<s.size()&&s[j]==s[i];j++);
            s=s.substr(0,i-2)+s.substr(j);
            i=max(i-3,1);
        }
    }
    int findMinStep(string board, string hand) {
        unordered_map<char,int>cnt;
        for(char x:hand) cnt[x]++;
        DFS(board,cnt);
        return res;
    }
};
