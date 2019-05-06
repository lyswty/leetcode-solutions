class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) return;
        sort(nums.begin(),nums.end(),greater<int>());
        int i=0,j=nums.size()/2;
        while(i<j){
            int cur=nums[j];
            for(int k=j;k>i;k--) nums[k]=nums[k-1];
            nums[i]=cur;
            j++;
            i+=2;
        }
    }
};
