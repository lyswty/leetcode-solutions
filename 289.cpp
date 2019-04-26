class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()||board[0].empty()) return;
        for(int i=0;i<board.size();i++) for(int j=0;j<board[0].size();j++){
            int cnt=0;
            if(i&&j&&abs(board[i-1][j-1])==1) cnt++;
            if(i&&abs(board[i-1][j])==1) cnt++;
            if(i&&j+1!=board[0].size()&&abs(board[i-1][j+1])==1) cnt++;
            if(j&&abs(board[i][j-1])==1) cnt++;
            if(j+1!=board[0].size()&&abs(board[i][j+1])==1) cnt++;
            if(i+1!=board.size()&&j&&abs(board[i+1][j-1])==1) cnt++;
            if(i+1!=board.size()&&abs(board[i+1][j])==1) cnt++;
            if(i+1!=board.size()&&j+1!=board[0].size()&&abs(board[i+1][j+1])==1) cnt++;
            if(board[i][j]==1&&(cnt<2||cnt>3)) board[i][j]=-1;
            if(!board[i][j]&&cnt==3) board[i][j]=2;
        }
        for(int i=0;i<board.size();i++) for(int j=0;j<board[0].size();j++){
            if(board[i][j]==-1) board[i][j]=0;
            else if(board[i][j]==2) board[i][j]=1;
        }
    }
};
