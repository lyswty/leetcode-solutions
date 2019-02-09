class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> out;
        for(int i=0;i+3<nums.size();i++){
            if(i&&nums[i-1]==nums[i]) continue;
            for(int j=i+1;j+2<nums.size();j++){
                if(j!=i+1&&nums[j-1]==nums[j]) continue;
                for(int k=j+1;k+1<nums.size();k++){
                    if(k!=j+1&&nums[k-1]==nums[k]) continue;
                    auto it=lower_bound(nums.begin()+k+1,nums.end(),target-nums[i]-nums[j]-nums[k]);
                    int x;
                    if(it!=nums.end()){
                        x=*it;
                        if(x+nums[i]+nums[j]+nums[k]==target){
                            vector<int>cur(4);
                            cur[0]=nums[i],cur[1]=nums[j],cur[2]=nums[k],cur[3]=x;
                            out.push_back(cur);
                        }
                    }
                }
            }
        }
        return out;
    }
};
