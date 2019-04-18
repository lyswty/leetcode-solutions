class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        if(nums.empty()) return res;
        deque<int>maxs;
        for(int i=0;i<k;i++){
            while(maxs.size()&&nums[i]>=nums[maxs.back()]) maxs.pop_back();
            maxs.push_back(i);
        }
        res.push_back(nums[maxs.front()]);
        for(int i=k;i<nums.size();i++){
            if(maxs.front()<=i-k) maxs.pop_front();
            while(maxs.size()&&nums[i]>=nums[maxs.back()]) maxs.pop_back();
            maxs.push_back(i);
            res.push_back(nums[maxs.front()]);
        }
        return res;
    }
};
