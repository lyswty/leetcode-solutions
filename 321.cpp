class Solution {
public:
    deque<int> maxList(vector<int>&nums,int k){
        int drop=nums.size()-k;
        deque<int>res;
        for(int num:nums){
            while(drop&&res.size()&&res.back()<num){
                drop--;
                res.pop_back();
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
    vector<int> merge(deque<int>nums1,deque<int>nums2){
        vector<int>res(nums1.size()+nums2.size());
        for(int i=0;i<res.size();i++){
            if(nums1>nums2){
                res[i]=nums1.front();
                nums1.pop_front();
            }
            else{
                res[i]=nums2.front();
                nums2.pop_front();
            }
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>res;
        for(int i=max(k-(int)nums2.size(),0);i<=min(k,(int)nums1.size());i++) res=max(res,merge(maxList(nums1,i),maxList(nums2,k-i)));
        return res;
    }
};
