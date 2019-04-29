class NumArray {
private:
    vector<int>sums;
public:
    NumArray(vector<int>& nums) {
        sums.resize(nums.size());
        if(nums.size()) sums[0]=nums[0];
        for(int i=1;i<nums.size();i++) sums[i]=sums[i-1]+nums[i];
    }
    
    int sumRange(int i, int j) {
        return i?sums[j]-sums[i-1]:sums[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
