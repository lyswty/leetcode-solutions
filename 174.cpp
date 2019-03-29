class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()||dungeon[0].empty()) return 1;
        vector<vector<pair<int,int>>>dp(dungeon.size(),vector<pair<int,int>>(dungeon[0].size()));
        vector<vector<pair<int,int>>>sum(dungeon.size(),vector<pair<int,int>>(dungeon[0].size()));
        sum[0][0].first=sum[0][0].second=dungeon[0][0];
        if(dungeon[0][0]>0) dp[0][0].first=dp[0][0].second=1;
        else dp[0][0].first=dp[0][0].second=-dungeon[0][0]+1;
        for(int i=1;i<max(dungeon.size(),dungeon[0].size());i++){
            if(i<dungeon.size()){
                sum[i][0].first=sum[i][0].second=sum[i-1][0].first+dungeon[i][0];
                dp[i][0].first=dp[i][0].second=max(dp[i-1][0].first,-sum[i][0].first+1);
            }
            if(i<dungeon[0].size()){
                sum[0][i].first=sum[0][i].second=sum[0][i-1].first+dungeon[0][i];
                dp[0][i].first=dp[0][i].second=max(dp[0][i-1].first,-sum[0][i].first+1);
            }
        }
        for(int i=1;i<dungeon.size();i++) for(int j=1;j<dungeon[0].size();j++){
            int upfirstsum=sum[i-1][j].first+dungeon[i][j],upfirstdp=max(-upfirstsum+1,dp[i-1][j].first);
            int upsecondsum=sum[i-1][j].second+dungeon[i][j],upseconddp=max(-upsecondsum+1,dp[i-1][j].second);
            int leftfirstsum=sum[i][j-1].first+dungeon[i][j],leftfirstdp=max(-leftfirstsum+1,dp[i][j-1].first);
            int leftsecondsum=sum[i][j-1].second+dungeon[i][j],leftseconddp=max(-leftsecondsum+1,dp[i][j-1].second);
            sum[i][j].first=upfirstsum,dp[i][j].first=upfirstdp;
            if(upseconddp<dp[i][j].first||upseconddp==dp[i][j].first&&upsecondsum>sum[i][j].first) dp[i][j].first=upseconddp,sum[i][j].first=upsecondsum;
            if(leftfirstdp<dp[i][j].first||leftfirstdp==dp[i][j].first&&leftfirstsum>sum[i][j].first) dp[i][j].first=leftfirstdp,sum[i][j].first=leftfirstsum;
            if(leftseconddp<dp[i][j].first||leftseconddp==dp[i][j].first&&leftsecondsum>sum[i][j].first) dp[i][j].first=leftseconddp,sum[i][j].first=leftsecondsum;
            sum[i][j].second=upfirstsum,dp[i][j].second=upfirstdp;
            if(upsecondsum>sum[i][j].second||upsecondsum==sum[i][j].second&&upseconddp<dp[i][j].second) sum[i][j].second=upsecondsum,dp[i][j].second=upseconddp;
            if(leftfirstsum>sum[i][j].second||leftfirstsum==sum[i][j].second&&leftfirstdp<dp[i][j].second) sum[i][j].second=leftfirstsum,dp[i][j].second=leftfirstdp;
            if(leftsecondsum>sum[i][j].second||leftsecondsum==sum[i][j].second&&leftseconddp<dp[i][j].second) sum[i][j].second=leftsecondsum,dp[i][j].second=leftseconddp;
        }
        return dp[dungeon.size()-1][dungeon[0].size()-1].first;
    }
};
