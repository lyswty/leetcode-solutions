class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<=0||t<0) return false;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            if(i-k-1>=0) s.erase(nums[i-k-1]);
            if(s.find(nums[i])!=s.end()) return true;
            s.insert(nums[i]);
            auto it=s.find(nums[i]);
            if(it!=s.begin()){
                if(long(*it)-*(--it)<=t) return true;
                it++;
            }
            it++;
            if(it!=s.end()&&long(*it)-*(--it)<=t) return true;
        }
        return false;
    }
};
