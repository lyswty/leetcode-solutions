class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int m=nums1.size(),n=nums2.size(),imin=0,imax=m;
        while(imin<=imax){
            int i=(imin+imax)/2;
            int j=(m+n+1)/2-i;
            if(i<m&&nums2[j-1]>nums1[i]) imin=i+1;
            else if(i>0&&nums1[i-1]>nums2[j]) imax=i-1;
            else{
                double minr,maxl;
                if(!i) maxl=nums2[j-1];
                else if(!j) maxl=nums1[i-1];
                else maxl=max(nums2[j-1],nums1[i-1]);
                if((m+n)%2) return maxl;
                if(i==m) minr=nums2[j];
                else if(j==n) minr=nums1[i];
                else minr=min(nums2[j],nums1[i]);
                return (minr+maxl)/2.0;
            }
        }
        return 0.0;
    }
};
