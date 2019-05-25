class Solution {
public:
    int split(vector<int>& nums,long sum){
        int res=1;
        long cursum=0;
        for(int i:nums){
            if(cursum+i>sum){
                cursum=i;
                res++;
            }
            else cursum+=i;
        }
        return res;
    }
    int splitArray(vector<int>& nums, int m) {
        long left=0,right=0;
        for(int x:nums){
            if(x>left) left=x;
            right+=x;
        }
        while(left<right){
            long mid=(left+right)/2;
            if(split(nums,mid)>m) left=mid+1;
            else right=mid;
        }
        return left;
    }
};
