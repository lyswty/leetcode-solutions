class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++) if(nums[i]==1){
            int j=i;
            for(j++;j<nums.size()&&nums[j]==1;j++);
            if(j-i>res) res=j-i;
            i=j-1;
        }
        return res;
    }
};
