class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1;i>=0;i--){
            if(!i){
                reverse(nums.begin(),nums.end());
                return;
            }
            if(nums[i]>nums[i-1]){
                sort(nums.begin()+i,nums.end());
                for(int j=i;j<nums.size();j++){
                    if(nums[j]>nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        return;
                    }
                }
            }
        }
    }
};
