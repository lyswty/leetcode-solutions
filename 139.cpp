class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
};
