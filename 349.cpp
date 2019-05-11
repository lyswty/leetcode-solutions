class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),insert_iterator<vector<int>>(res,res.begin()));
        set<int>s(res.begin(),res.end());
        return vector<int>(s.begin(),s.end());
    }
};
