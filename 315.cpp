class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>res(nums.size());
        deque<int>op;
        for(int i=nums.size()-1;i>=0;i--){
            auto it=lower_bound(op.begin(),op.end(),nums[i]);
            res[i]=it-op.begin();
            op.insert(it,nums[i]);
        }
        return res;
    }
};
