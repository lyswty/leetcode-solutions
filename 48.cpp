class Solution {
public:
    void rotateonelayer(vector<vector<int>>&matrix,int x){
        if(x==matrix.size()/2) return;
        int l=x,r=matrix.size()-1-x;
        for(int i=0;i<r-l;i++){
            int cur=matrix[l][l+i];
            matrix[l][l+i]=matrix[r-i][l];
            matrix[r-i][l]=matrix[r][r-i];
            matrix[r][r-i]=matrix[l+i][r];
            matrix[l+i][r]=cur;
        }
        rotateonelayer(matrix,x+1);
    }
    void rotate(vector<vector<int>>& matrix) {
        rotateonelayer(matrix,0);
    }
};
