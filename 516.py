class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n=len(s)
        dp=[[0]*n for i in range(n)]
        for i in range(n):
            dp[i][i]=1
        for i in range(1,n):
            for j in range(i-1,-1,-1):
                if s[j]==s[i]:
                    dp[j][i]=dp[j+1][i-1]+2
                else:
                    dp[j][i]=max(dp[j+1][i],dp[j][i-1])
        return dp[0][n-1]
