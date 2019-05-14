class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()<2) return nums;
        sort(nums.begin(),nums.end());
        int *dp=new int[nums.size()],*last=new int[nums.size()];
        int max=1,maxi=0;
        fill(dp,dp+nums.size(),1);
        for(int i=0;i<nums.size();i++) last[i]=i;
        for(int i=1;i<nums.size();i++) for(int j=0;j<i;j++) if((nums[j]%nums[i]==0||nums[i]%nums[j]==0)&&dp[j]+1>dp[i]){
            dp[i]=dp[j]+1;
            last[i]=j;
            if(dp[i]>max){
                max=dp[i];
                maxi=i;
            }
        }
        vector<int>res;
        for(int i=maxi;res.empty()||nums[i]!=res.back();i=last[i]) res.push_back(nums[i]);
        return res;
    }
};
