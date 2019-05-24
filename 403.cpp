class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]>1) return false;
        vector<vector<int>>dp(stones.size(),vector<int>());
        dp[0].push_back(1);
        for(int i=1;i<stones.size();i++) for(int j=i-1;j>=0;j--){
            int temp=stones[i]-stones[j];
            for(int num:dp[j]) if(abs(temp-num)<=1){
                dp[i].push_back(temp);
                break;
            }
        }
        return dp.back().size();
    }
};
