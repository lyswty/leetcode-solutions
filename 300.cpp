class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int *dp=new int[nums.size()];
        dp[0]=1;
        int max=1;
        for(int i=1;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++) if(nums[i]>nums[j]&&dp[j]+1>dp[i]) dp[i]=dp[j]+1;
            if(dp[i]>max) max=dp[i];
        }
        return max;
    }
};
