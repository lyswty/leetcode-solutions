class Solution {
public:
    bool judge(vector<vector<char>>& board,int i,int j,char k){
        int a=i-i%3,b=j-j%3;
        for(int x=0;x<9;x++){
            int m,n;
            if(x>5){
                m=x-6;
                n=2;
            }
            else if(x>2){
                m=x-3;
                n=1;
            }
            else{
                m=x;
                n=0;
            }
            if((board[i][x]==k&&x!=j)||(board[x][j]==k&&x!=i)||(k==board[a+m][b+n]&&(i!=a+m||j!=b+n))) return false;
        }
        return true;
    }
    bool DFS(vector<vector<char>>& board,int i,int j){
        for(;j<9&&board[i][j]!='.';j++);
        if(j==9){
            for(;i<9;i++){
                for(j=0;j<9&&board[i][j]!='.';j++);
                if(j<9) break;
            }
        }
        if(i==9) return true;
        for(int x=1;x<10;x++){
            if(judge(board,i,j,x+'0')) board[i][j]=x+'0';
            else continue;
            if(DFS(board,i,j)) return true;
            board[i][j]='.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        DFS(board,0,0);
    }
};
