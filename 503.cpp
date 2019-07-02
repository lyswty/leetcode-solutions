class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>res(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]<res[i-1]) res[i]=res[i-1];
            for(int j=(i+1==nums.size()?0:i+1);j%nums.size()!=i;j++){
                if(j==nums.size()) j=0;
                if(nums[i]<nums[j]){
                    res[i]=nums[j];
                    break;
                }
            }
        }
        return res;
    }
};
