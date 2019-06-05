class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>res(nums.size());
        for(int i=1;i<=nums.size();i++) res[i-1]=i;
        int size=0;
        for(int x:nums)
            if(!res[x-1]) size++;
            else res[x-1]=0;
        int i=0;
        for(int j=0;j<res.size();j++) if(res[j]) swap(res[i++],res[j]);
        res.resize(size);
        return res;
    }
};
