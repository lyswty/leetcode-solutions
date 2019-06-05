class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3) return false;
        vector<pair<int,int>>former;
        int min=nums[0],max=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>min&&nums[i]<max) return true;
            for(auto x:former) if(nums[i]>x.first&&nums[i]<x.second) return true;
            if(nums[i]<min){
                if(min<max) former.push_back(make_pair(min,max));
                min=max=nums[i];
            }
            else if(nums[i]>max) max=nums[i];
        }
        return false;
    }
};
