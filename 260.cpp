class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum=0;
        for(auto num:nums) sum^=num;
        int k;
        for(k=0;sum&&(!((sum>>k)&1));k++);
        int a1=0,a2=0;
        for(auto num:nums){
            if(((num>>k)&1)==1) a1=a1^num;
            else a2=a2^num;
        }
        return {a1,a2};
    }
};
