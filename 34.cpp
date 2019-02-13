class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>out(2,-1);
        vector<int>::iterator it=lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end()||*it!=target) return out;
        out[0]=distance(nums.begin(),it);
        it=upper_bound(it,nums.end(),target);
        out[1]=distance(nums.begin(),it-1);
        return out;
    }
};
