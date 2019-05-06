class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *dp=new int[amount+1];
        fill(dp,dp+amount+1,INT_MAX);
        dp[0]=0;
        for(int coin:coins) for(int i=coin;i<=amount;i++) dp[i]=dp[i]-1>dp[i-coin]?dp[i-coin]+1:dp[i];
        if(dp[amount]!=INT_MAX) return dp[amount];
        else return -1;
    }
};
