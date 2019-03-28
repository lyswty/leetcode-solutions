class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>cnts;
        for(int i=0;i<nums.size();i++) if(++cnts[nums[i]]>nums.size()/2) return nums[i];
        return -1;
    }
};
