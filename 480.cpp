class Solution {
public:
    void adjust(multiset<int>&s1,multiset<int>&s2){
        if(s1.size()<s2.size()){
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
        else if(s1.size()-s2.size()>1){
            s2.insert(*s1.rbegin());
            s1.erase((++s1.rbegin()).base());
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>s1,s2;
        vector<double>res;
        if(nums.size()<k) return res;
        for(int i=0;i<k;i++){
            if(s1.empty()||nums[i]<=*s1.rbegin()) s1.insert(nums[i]);
            else s2.insert(nums[i]);
            adjust(s1,s2);
        }
        if(s1.size()==s2.size()) res.emplace_back(((double)*s1.rbegin()+*s2.begin())/2);
        else res.emplace_back(*s1.rbegin());
        for(int i=k;i<nums.size();i++){
            if(s1.empty()||nums[i-k]>*s1.rbegin()) s2.erase(s2.find(nums[i-k]));
            else s1.erase(s1.find(nums[i-k]));
            adjust(s1,s2);
            if(s1.empty()||nums[i]<=*s1.rbegin()) s1.insert(nums[i]);
            else s2.insert(nums[i]);
            adjust(s1,s2);
            if(s1.size()==s2.size()) res.emplace_back(((double)*s1.rbegin()+*s2.begin())/2);
            else res.emplace_back(*s1.rbegin());
        }
        return res;
    }
};
