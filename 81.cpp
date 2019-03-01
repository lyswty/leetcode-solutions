class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(nums[mid]>nums[start]){
                auto it=lower_bound(nums.begin()+start,nums.begin()+mid,target);
                if(it!=nums.begin()+mid+1&&*it==target) return true;
                else start=mid+1;
            }
            else if(nums[mid]==nums[start]){
                bool flag=true;
                for(int i=start+1;i<=mid;i++) if(nums[start]!=nums[i]){
                    flag=false;
                    break;
                }
                if(!flag){
                    auto it=lower_bound(nums.begin()+mid+1,nums.begin()+end,target);
                    if(it!=nums.begin()+end+1&&*it==target) return true;
                    else end=mid;
                } 
                else if(nums[start]==target) return true;
                else start=mid+1;
            }
            else{
                auto it=lower_bound(nums.begin()+mid+1,nums.begin()+end,target);
                if(it!=nums.begin()+end+1&&*it==target) return true;
                else end=mid;
            }
        }
        if(start==end&&nums[start]==target) return true;
        return false;
    }
};
