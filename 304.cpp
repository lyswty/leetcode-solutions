class NumMatrix {
private:
    vector<vector<int>>summatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()&&matrix[0].size()){
            summatrix.assign(matrix.size(),vector<int>(matrix[0].size()));
            summatrix[0][0]=matrix[0][0];
            for(int i=1;i<matrix[0].size();i++) summatrix[0][i]=summatrix[0][i-1]+matrix[0][i];
            for(int i=1;i<matrix.size();i++) summatrix[i][0]=summatrix[i-1][0]+matrix[i][0];
            for(int i=1;i<matrix.size();i++) for(int j=1;j<matrix[0].size();j++) summatrix[i][j]=summatrix[i-1][j]+summatrix[i][j-1]-summatrix[i-1][j-1]+matrix[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1&&col1) return summatrix[row2][col2]-summatrix[row2][col1-1]-summatrix[row1-1][col2]+summatrix[row1-1][col1-1];
        if(col1) return summatrix[row2][col2]-summatrix[row2][col1-1];
        if(row1) return summatrix[row2][col2]-summatrix[row1-1][col2];
        return summatrix[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
