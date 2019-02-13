class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int half=(left+right)/2;
            if(nums[left]<nums[half]){
                auto it=lower_bound(nums.begin()+left,nums.begin()+half+1,target);
                if(it==nums.begin()+half+1||*it!=target){
                    if(nums[half+1]<nums[right]){
                        auto it=lower_bound(nums.begin()+half+1,nums.begin()+right+1,target);
                        if(it==nums.begin()+right+1||*it!=target) return -1;
                        else return distance(nums.begin(),it);
                    }
                    else left=half+1;
                }
                else return distance(nums.begin(),it);
            }
            else{
                auto it=lower_bound(nums.begin()+half+1,nums.begin()+right+1,target);
                if(it==nums.begin()+right+1||*it!=target) right=half;
                else return distance(nums.begin(),it);
            }
        }
        if(left==right&&nums[left]==target) return left;
        else return -1;
    }
};
