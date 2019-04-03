class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return;
        k%=nums.size();
        int start=0;
        while(k){
            for(int i=nums.size()-k;i<nums.size();i++) swap(nums[start+i-(nums.size()-k)],nums[i]);
            int l=nums.size()-start;
            start+=k;
            k%=l-k;
        }
    }
};
