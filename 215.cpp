//懒得写快排了- -大致就是快排一趟完成之后只排n在的那一端，直到排序的中心值是n然后返回
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(),nums.begin()+k-1,nums.end(),greater<int>());
        return nums[k-1];
    }
};
