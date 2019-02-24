class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.length()==0) return word2.length();
        if(word2.length()==0) return word1.length();
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size()));
        bool flag1=false,flag2=false;
        if(word1[0]==word2[0]){
            flag1=flag2=true;
            dp[0][0]=0;
        }
        else dp[0][0]=1;
        for(int i=1;i<max(word1.size(),word2.size());i++){
            if(i<word1.size())
                if(word1[i]==word2[0]&&!flag1){
                    flag1=true;
                    dp[i][0]=dp[i-1][0];
                }
                else dp[i][0]=dp[i-1][0]+1;
            if(i<word2.size())
                if(word1[0]==word2[i]&&!flag2){
                    flag2=true;
                    dp[0][i]=dp[0][i-1];
                }
                else dp[0][i]=dp[0][i-1]+1;
        }
        for(int i=1;i<word1.size();i++) for(int j=1;j<word2.size();j++){
            int min=word1[i]==word2[j]?dp[i-1][j-1]:dp[i-1][j-1]+1;
            if(dp[i-1][j]+1<min) min=dp[i-1][j]+1;
            if(dp[i][j-1]+1<min) min=dp[i][j-1]+1;
            dp[i][j]=min;
        }
        return dp[word1.size()-1][word2.size()-1];
    }
};
