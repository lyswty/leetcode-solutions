class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(auto num:nums){
                if((num>>i)&1) cnt++;
            }
            res+=cnt*(nums.size()-cnt);
        }
        return res;
    }
};
