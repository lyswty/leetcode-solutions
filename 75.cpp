class Solution {
public:
    void quicksort(vector<int>&nums,int start,int end){
        if(end-start+1<2) return;
        if(end-start+1==2){
            if(nums[start]>nums[end]) swap(nums[start],nums[end]);
            return;
        }
        if(nums[start]>nums[start+1]) swap(nums[start],nums[start+1]);
        if(nums[start+1]>nums[start+2]) swap(nums[start+1],nums[start+2]);
        if(nums[start]>nums[start+1]) swap(nums[start],nums[start+1]);
        swap(nums[start+2],nums[end]);
        int i=start+1,j=end-1;
        while(i<j){
            while(nums[i]<=nums[j]&&i<j) j--;
            if(i==j) break;
            swap(nums[i],nums[j]);
            while(nums[i]<=nums[j]&&i<j) i++;
            if(i==j) break;
            swap(nums[i],nums[j]);
        }
        quicksort(nums,start,i);
        quicksort(nums,i+1,end);
    }
    void sortColors(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
    }
};
