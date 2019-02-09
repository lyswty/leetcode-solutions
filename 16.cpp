class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX,x;
        sort(nums.begin(),nums.end());
        for(int i=0;i+2<nums.size();i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j+1<nums.size();j++){
                if(j!=i+1&&nums[j]==nums[j-1]) continue;
                auto it=lower_bound(nums.begin()+j+1,nums.end(),target-nums[i]-nums[j]);
                if(it==nums.end()) it--;
                int x1=nums[i]+nums[j]+*it;
                if(--it!=nums.begin()+j){
                    int x2=nums[i]+nums[j]+*it;
                    if(abs(x2-target)<abs(x1-target)) x1=x2;
                }
                if(x1==target) return x1;
                if(abs(x1-target)<diff){
                    diff=abs(x1-target);
                    x=x1;
                }
            }
        }
        return x;
    }
};
