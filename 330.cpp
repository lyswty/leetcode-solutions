class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res=0,i=0;
        long mis=1;
        while(mis<=n){
            if(i<nums.size()&&nums[i]<=mis) mis+=nums[i++];
            else{
                mis*=2;
                res++;
            }
        }
        return res;
    }
};
