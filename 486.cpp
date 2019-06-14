class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()==1||nums.size()%2==0) return true;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int i=0;i<nums.size();i++){
            dp[i][i]=nums[i];
            if(i+1<nums.size()) dp[i][i+1]=abs(nums[i]-nums[i+1]);
        }
        for(int i=nums.size()-3;i>=0;i--) for(int j=i+2;j<nums.size();j++) dp[i][j]=max(nums[j]-dp[i][j-1],nums[i]-dp[i+1][j]);
        return dp[0][nums.size()-1]>=0;
    }
};
