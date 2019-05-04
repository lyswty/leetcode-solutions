class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.resize(nums.size()+2);
        for(int i=nums.size()-2;i>0;i--) nums[i]=nums[i-1];
        nums[0]=1;
        nums[nums.size()-1]=1;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),0));
        for(int l=2;l<nums.size();l++) for(int i=0;i+l<nums.size();i++){
            int j=i+l;
            for(int k=i+1;k<j;k++) dp[i][j]=max(dp[i][j],nums[i]*nums[k]*nums[j]+dp[i][k]+dp[k][j]);
        }
        return dp[0][nums.size()-1];
    }
};
