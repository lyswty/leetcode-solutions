class Solution {
public:
    int MAX=-1;
    void DFS(vector<vector<int>>&matrix,vector<vector<int>>&length,int x,int y){
        if(length[x][y]!=-1) return;
        if(x>0&&matrix[x][y]<matrix[x-1][y]){
            DFS(matrix,length,x-1,y);
            length[x][y]=length[x-1][y];
        }
        if(x+1<matrix.size()&&matrix[x][y]<matrix[x+1][y]){
            DFS(matrix,length,x+1,y);
            if(length[x][y]<length[x+1][y]) length[x][y]=length[x+1][y];
        }
        if(y>0&&matrix[x][y]<matrix[x][y-1]){
            DFS(matrix,length,x,y-1);
            if(length[x][y]<length[x][y-1]) length[x][y]=length[x][y-1];
        }
        if(y+1<matrix[0].size()&&matrix[x][y]<matrix[x][y+1]){
            DFS(matrix,length,x,y+1);
            if(length[x][y]<length[x][y+1]) length[x][y]=length[x][y+1];
        }
        length[x][y]++;
        if(length[x][y]>MAX) MAX=length[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        vector<vector<int>>length(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int x=0;x<matrix.size();x++) for(int y=0;y<matrix[0].size();y++) DFS(matrix,length,x,y);
        return MAX+1;
    }
};
