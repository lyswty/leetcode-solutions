class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size());
        res[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>0;i--) res[i]=res[i+1]*nums[i];
        int total=1;
        for(int i=0;i+1<nums.size();i++){
            res[i]=res[i+1]*total;
            total*=nums[i];
        }
        res[nums.size()-1]=total;
        return res;
    }
};
