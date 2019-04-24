class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=nums.size()*(nums.size()+1)/2;
        int s=0;
        for(int i:nums) s+=i;
        return sum-s;
    }
};
