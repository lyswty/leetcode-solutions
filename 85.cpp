class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        vector<vector<int>>row(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            int height=0;
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(matrix[i][j]=='1') height++;
                else height=0;
                row[i][j]=height;
            }
        }
        int max=0;
        for(int j=0;j<row[0].size();j++){
            for(int i=0;i<row.size();i++){
                int left=i,right=i;
                bool l=true,r=true;
                while(l||r){
                    if(l){
                        left--;
                        if(left<0||row[left][j]<row[i][j]) l=false;
                    }
                    if(r){
                        right++;
                        if(right==row.size()||row[right][j]<row[i][j]) r=false;
                    }
                }
                if((right-left-1)*row[i][j]>max) max=(right-left-1)*row[i][j];
            }
        }
        return max;
    }
};
