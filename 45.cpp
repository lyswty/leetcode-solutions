//傻了，用递归DFS回溯写了出来发现超时，然后发现这题不就是PAT A1033 To Fill or Not to Fill的简化版吗。
//根本不需要DFS，直接每一跳选择下一次能最大距离的那个点就好了

class Solution {
public:
    int jump(vector<int>&nums,int x){
        if(x==nums.size()-1) return 0;
        if(nums[x]>=nums.size()-1-x) return 1;
        int max=0,maxi=-1;
        for(int i=x+1;i<nums.size()&&i-x<=nums[x];i++) if(i-x+nums[i]>max){
            max=i-x+nums[i];
            maxi=i;
        }
        return jump(nums,maxi)+1;
    }
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        return jump(nums,0);
    }
};
