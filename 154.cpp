class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1||nums[0]<nums[nums.size()-1]) return nums[0];
        int start=0,end=nums.size()-1;
        while(start<end){
            int mid=(start+end)/2,i=start,j=mid+1;
            while(i!=mid&&nums[i]==nums[mid]) i++;
            while(j!=end&&nums[j]==nums[end]) j++;
            if((i==mid||nums[i]<nums[mid])&&(j==end||nums[j]<nums[end])) return min(nums[i],nums[j]);
            if(i==mid||nums[i]<nums[mid]) start=mid+1;
            else end=mid;
        }
        return nums[start];
    }
};
