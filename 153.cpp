class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<=nums[nums.size()-1]) return nums[0];
        int start=0,end=nums.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(nums[start]<=nums[mid]&&nums[mid+1]<=nums[end]) return nums[start]<nums[mid+1]?nums[start]:nums[mid+1];
            if(nums[start]<=nums[mid]) start=mid+1;
            else end=mid;
        }
        return nums[start];
    }
};
