class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int small=1,big=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) big=small+1;
            if(nums[i]<nums[i-1]) small=big+1;
        }
        return big>small?big:small;
    }
};
