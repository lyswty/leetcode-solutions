class Solution {
public:
    void DFS(int x,int y,vector<vector<char>>&board){
        board[x][y]='T';
        if(x!=0&&board[x-1][y]=='O') DFS(x-1,y,board);
        if(x+1!=board.size()&&board[x+1][y]=='O') DFS(x+1,y,board);
        if(y!=0&&board[x][y-1]=='O') DFS(x,y-1,board);
        if(y+1!=board[0].size()&&board[x][y+1]=='O') DFS(x,y+1,board);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty()) return;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O') DFS(i,0,board);
            if(board[0].size()!=1&&board[i][board[0].size()-1]=='O') DFS(i,board[0].size()-1,board);
        }
        for(int i=0;i<board[0].size();i++){ 
            if(board[0][i]=='O') DFS(0,i,board);
            if(board.size()!=1&&board[board.size()-1][i]=='O') DFS(board.size()-1,i,board);
        }
        for(int i=0;i<board.size();i++) for(int j=0;j<board[0].size();j++)
            if(board[i][j]=='O') board[i][j]='X';
            else if(board[i][j]=='T') board[i][j]='O';
    }
};
