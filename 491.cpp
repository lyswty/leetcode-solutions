class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size());
        set<vector<int>>res;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++) if(nums[i]>=nums[j]){
                dp[i].emplace_back(vector<int>(2));
                dp[i].back()[0]=nums[j];
                dp[i].back()[1]=nums[i];
                for(auto sequence:dp[j]){
                    sequence.emplace_back(nums[i]);
                    dp[i].emplace_back(sequence);
                }
            }
            res.insert(dp[i].begin(),dp[i].end());
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};
