class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int cur=1,left=0,top=0,right=n-1,end=n-1;
        while(cur<=n*n){
            if(left==right) matrix[left][left]=cur++;
            for(int i=left;i<right;i++) matrix[top][i]=cur++;
            for(int i=top;i<end;i++) matrix[i][right]=cur++;
            for(int i=right;i>left;i--) matrix[end][i]=cur++;
            for(int i=end;i>top;i--) matrix[i][left]=cur++;
            left++,right--,top++,end--;
        }
        return matrix;
    }
};
