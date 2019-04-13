class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        int maxa=0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<max(matrix.size(),matrix[0].size());i++){
            if(i<matrix.size()){
                dp[i][0]=matrix[i][0]=='1'?1:0;
                if(dp[i][0]>maxa) maxa=dp[i][0];
            }
            if(i<matrix[0].size()){
                dp[0][i]=matrix[0][i]=='1'?1:0;
                if(dp[0][i]>maxa) maxa=dp[0][i];
            }
        }
        for(int i=1;i<matrix.size();i++) for(int j=1;j<matrix[0].size();j++){
            if(matrix[i][j]=='0') dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j-1];
                if(dp[i][j-1]<dp[i][j]) dp[i][j]=dp[i][j-1];
                if(dp[i-1][j]<dp[i][j]) dp[i][j]=dp[i-1][j];
                dp[i][j]++;
                if(dp[i][j]>maxa) maxa=dp[i][j];
            }
        }
        return maxa*maxa;
    }
};
