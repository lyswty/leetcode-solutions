class Solution {
private:
    vector<int>nums;
public:
    Solution(vector<int>& nums) {
        Solution::nums=nums;
    }
    
    int pick(int target) {
        int cnt=0;
        int res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                cnt++;
                if(rand()%cnt==0) res=i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
