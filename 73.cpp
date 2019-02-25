class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        bool h=matrix[0][0],l=matrix[0][0];
        for(int i=0;i<matrix.size();i++) for(int j=0;j<matrix[0].size();j++) if(matrix[i][j]==0){
            if(!i) l=false;
            if(!j) h=false;
            matrix[i][0]=matrix[0][j]=0;
        }
        for(int i=1;i<matrix.size();i++) if(!matrix[i][0]) for(int j=0;j<matrix[i].size();j++) matrix[i][j]=0;
        for(int i=1;i<matrix[0].size();i++) if(!matrix[0][i]) for(int j=0;j<matrix.size();j++) matrix[j][i]=0;
        if(!h) for(int i=1;i<matrix.size();i++) matrix[i][0]=0;
        if(!l) for(int i=1;i<matrix[0].size();i++) matrix[0][i]=0;
    }
};
