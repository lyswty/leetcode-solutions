class Solution {
public:
    int dfs(int i,vector<int>& nums,long goal,vector<unordered_map<int,long>>& memory){
        if(memory[i].find(goal)!=memory[i].end()) return memory[i][goal];
        else if(i==nums.size()-1) return 0;
        memory[i][goal]=dfs(i+1,nums,goal-nums[i],memory)+dfs(i+1,nums,goal+nums[i],memory);
        return memory[i][goal];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int,long>>memory(nums.size());
        memory[nums.size()-1][nums.back()]=1;
        memory[nums.size()-1][-nums.back()]=1;
        if(!nums.back()) memory[nums.size()-1][nums.back()]=2;
        return dfs(0,nums,S,memory);
    }
};
