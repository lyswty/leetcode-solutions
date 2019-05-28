class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res=0;
        if(board.empty()||board[0].empty()) return res;
        for(int i=0;i<board.size();i++) for(int j=0;j<board[0].size();j++) if(board[i][j]=='X'&&(!i||board[i-1][j]=='.')&&(!j||board[i][j-1]=='.')) res++;
        return res;
    }
};
