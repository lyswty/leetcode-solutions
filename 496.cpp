class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>s;
        for(int num:nums2){
            while(s.size()&&num>s.top()){
                mp[s.top()]=num;
                s.pop();
            }
            s.push(num);
        }
        for(int i=0;i<nums1.size();i++) nums1[i]=mp.find(nums1[i])!=mp.end()?mp[nums1[i]]:-1;
        return nums1;
    }
};
