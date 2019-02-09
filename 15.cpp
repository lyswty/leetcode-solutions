class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>out;
        sort(nums.begin(),nums.end());
        for(int i=0;i+2<nums.size();i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j+1<nums.size();j++){
                if(j!=i+1&&nums[j]==nums[j-1]) continue;
                int x=*lower_bound(nums.begin()+j+1,nums.end(),-nums[i]-nums[j]);
                if(nums[i]+nums[j]+x==0){
                    vector<int>cur(3);
                    cur[0]=nums[i],cur[1]=nums[j],cur[2]=x;
                    out.push_back(cur);
                }
            }
        }
        return out;
    }
};
