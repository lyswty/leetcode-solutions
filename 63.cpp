class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long>>dp(obstacleGrid.size(),vector<long>(obstacleGrid[0].size()));
        if(obstacleGrid[0][0]) return 0;
        else dp[0][0]=1;
        for(int i=1;i<max(obstacleGrid.size(),obstacleGrid[0].size());i++){
            if(i<obstacleGrid.size()){
                if(obstacleGrid[i][0]) dp[i][0]=0;
                else dp[i][0]=dp[i-1][0];
            }
            if(i<obstacleGrid[0].size()){
                if(obstacleGrid[0][i]) dp[0][i]=0;
                else dp[0][i]=dp[0][i-1];
            }
        }
        for(int i=1;i<obstacleGrid.size();i++) for(int j=1;j<obstacleGrid[0].size();j++)
            if(obstacleGrid[i][j]) dp[i][j]=0;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
