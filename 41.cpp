class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) mp[nums[i]]=true;
            if(nums[i]>max) max=nums[i];
        }
        for(int i=1;i<max;i++) if(!mp[i]) return i;
        return max+1;
    }
};
