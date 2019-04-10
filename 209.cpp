class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int cnt=INT_MAX,sum=0,left=0,right=0;
        while(right<=nums.size()){
            if(sum<s&&right<nums.size()) sum+=nums[right++];
            else if(sum<s) break;
            else if(sum>=s){
                cnt=cnt>right-left?right-left:cnt;
                sum-=nums[left++];
            }
        }
        return cnt==INT_MAX?0:cnt;
    }
};
