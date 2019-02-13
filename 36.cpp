class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int>s(10,0),r(10,0);
            for(int j=0;j<9;j++){
                if(isdigit(board[i][j])){
                    s[board[i][j]-'0']++;
                    if(s[board[i][j]-'0']>1) return false;
                }
                if(isdigit(board[j][i])){
                    r[board[j][i]-'0']++;
                    if(r[board[j][i]-'0']>1) return false;
                }
            }
        }
        for(int i=0;i<9;i+=3) for(int j=0;j<9;j+=3){
            vector<int>s(10,0);
            for(int a=0;a<3;a++) for(int b=0;b<3;b++){
                if(isdigit(board[i+a][j+b])){
                    s[board[i+a][j+b]-'0']++;
                    if(s[board[i+a][j+b]-'0']>1) return false;
                }
            }
        }
        return true;
    }
};
