class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(!nums[i-1]&&nums[i]){
                int j;
                for(j=i-1;j>=0&&!nums[j];j--);
                j++;
                swap(nums[i],nums[j]);
            }
        }
    }
};
