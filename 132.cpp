class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<s.size();i++){
            dp[i][i]=true;
            if(i&&s[i]==s[i-1]) dp[i-1][i]=true;
            else if(i&&s[i]!=s[i-1]) dp[i-1][i]=false;
        }
        for(int i=2;i<s.size();i++) for(int j=0;j+i<s.size();j++)
            if(s[j]==s[i+j]&&dp[j+1][i+j-1]) dp[j][j+i]=true;
            else dp[j][j+i]=false;
        int *dp2=new int[s.size()];
        dp2[0]=0;
        for(int i=1;i<s.size();i++){
            dp2[i]=dp2[i-1]+1;
            if(dp[0][i]) dp2[i]=0;
            else for(int j=1;j<i;j++) if(dp[j][i]) dp2[i]=dp2[j-1]+1<dp2[i]?dp2[j-1]+1:dp2[i];
        }
        return dp2[s.size()-1];
    }
};
