class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int cnt=0;
        multiset<long long>sums;
        sums.insert(0);
        long long sum=0;
        for(int i:nums){
            sum+=i;
            cnt+=distance(sums.lower_bound(sum-upper),sums.upper_bound(sum-lower));
            sums.insert(sum);
        }
        return cnt;
    }
};
