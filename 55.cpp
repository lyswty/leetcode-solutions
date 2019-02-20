class Solution {
public:
    bool jump(const vector<int>& nums,int x){
        if(x+nums[x]+1>=nums.size()) return true;
        int max=nums[x],maxi=-1;
        for(int i=x+1;i<nums.size()&&i-x<=nums[x];i++) if(i-x+nums[i]>max){
            max=i-x+nums[i];
            maxi=i;
        }
        if(maxi==-1) return false;
        return jump(nums,maxi);
    }
    bool canJump(vector<int>& nums) {
        return jump(nums,0);
    }
};
