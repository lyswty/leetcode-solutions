class Solution {
public:
    bool wordBreak1(string s, vector<string>& wordDict) {
        vector<bool>dp(s.length()+1,false);
        dp[0]=true;
        for(int i=1;i<dp.size();i++) for(int j=0;j<wordDict.size();j++){
            if(i-(int)wordDict[j].length()>=0&&dp[i-(int)wordDict[j].length()]&&s.substr(i-(int)wordDict[j].length(),wordDict[j].length())==wordDict[j]){
                dp[i]=true;
                break;
            }
        }
        return dp[s.size()];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(!wordBreak1(s,wordDict)) return vector<string>();
        vector<vector<string>>dp(s.size()+1);
        dp[0].push_back("");
        for(int i=1;i<dp.size();i++) for(int j=0;j<wordDict.size();j++){
            if(i-(int)wordDict[j].length()>=0&&dp[i-(int)wordDict[j].length()].size()&&s.substr(i-(int)wordDict[j].length(),wordDict[j].length())==wordDict[j]) for(int k=0;k<dp[i-(int)wordDict[j].length()].size();k++) dp[i].push_back(dp[i-(int)wordDict[j].length()][k]+' '+wordDict[j]);
        }
        for(int i=0;i<dp[s.size()].size();i++) dp[s.size()][i]=dp[s.size()][i].substr(1);
        return dp[s.size()];
    }
};
