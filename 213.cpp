class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return nums[0]>nums[1]?nums[0]:nums[1];
        int *dp1=new int[nums.size()],*dp2=new int[nums.size()];
        dp1[0]=nums[0],dp1[1]=nums[0]>nums[1]?nums[0]:nums[1];
        dp2[nums.size()-1]=nums[nums.size()-1],dp2[nums.size()-2]=nums[nums.size()-1]>nums[nums.size()-2]?nums[nums.size()-1]:nums[nums.size()-2];
        for(int i=2;i<nums.size();i++){
            dp1[i]=dp1[i-2]+nums[i]>dp1[i-1]?dp1[i-2]+nums[i]:dp1[i-1];
            dp2[nums.size()-1-i]=dp2[nums.size()+1-i]+nums[nums.size()-1-i]>dp2[nums.size()-i]?nums[nums.size()-1-i]+dp2[nums.size()+1-i]:dp2[nums.size()-i];
        }
        if(dp1[nums.size()-1]==dp1[nums.size()-3]+nums[nums.size()-1]&&dp2[0]==dp2[2]+nums[0]) return dp1[nums.size()-2]>dp2[1]?dp1[nums.size()-2]:dp2[1];
        else return dp2[0];
    }
};
