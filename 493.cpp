class Solution {
public:
    int merge(vector<long>& prim,vector<long>& twice,int l,int r){
        if(r-l<=1) return 0;
        int mid=(r+l)/2,cnt=merge(prim,twice,l,mid)+merge(prim,twice,mid,r);
        for(int i=l;i<mid;i++) cnt+=lower_bound(twice.begin()+mid,twice.begin()+r,prim[i])-twice.begin()-mid;
        inplace_merge(prim.begin()+l,prim.begin()+mid,prim.begin()+r);
        inplace_merge(twice.begin()+l,twice.begin()+mid,twice.begin()+r);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        vector<long>prim(nums.size()),twice(nums.size());
        for(int i=0;i<nums.size();i++){
            prim[i]=nums[i];
            twice[i]=prim[i]*2;
        }
        return merge(prim,twice,0,nums.size());
    }
};
