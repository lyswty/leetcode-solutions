class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>>dp(s.size()+1,vector<long>(t.size()+1,0));
        for(int i=0;i<s.size()+1;i++) dp[i][0]=1;
        for(int i=1;i<t.size()+1;i++) for(int j=1;j<s.size()+1;j++){
            if(s[j-1]==t[i-1]) dp[j][i]=dp[j-1][i]+dp[j-1][i-1];
            else dp[j][i]=dp[j-1][i];
        }
        return dp[s.size()][t.size()];
    }
};
