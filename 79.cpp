class Solution {
public:
    bool DFS(vector<vector<char>>&board,string &word,vector<vector<bool>>&visited,int x,int i,int j){
        if(x==word.size()) return true;
        if(i!=0&&!visited[i-1][j]&&word[x]==board[i-1][j]){
            visited[i-1][j]=true;
            if(DFS(board,word,visited,x+1,i-1,j)) return true;
            visited[i-1][j]=false;
        }
        if(i+1<board.size()&&!visited[i+1][j]&&word[x]==board[i+1][j]){
            visited[i+1][j]=true;
            if(DFS(board,word,visited,x+1,i+1,j)) return true;
            visited[i+1][j]=false;
        }
        if(j!=0&&!visited[i][j-1]&&word[x]==board[i][j-1]){
            visited[i][j-1]=true;
            if(DFS(board,word,visited,x+1,i,j-1)) return true;
            visited[i][j-1]=false;
        }
        if(j+1<board[0].size()&&!visited[i][j+1]&&word[x]==board[i][j+1]){
            visited[i][j+1]=true;
            if(DFS(board,word,visited,x+1,i,j+1)) return true;
            visited[i][j+1]=false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()||board.empty()||board[0].empty()) return false;
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++) for(int j=0;j<board[0].size();j++){
            if(board[i][j]==word[0]){
                visited[i][j]=true;
                if(DFS(board,word,visited,1,i,j)) return true;
                visited[i][j]=false;
            }
        }
        return false;
    }
};
