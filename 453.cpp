class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min=INT_MAX,res=0;
        for(int num:nums) min=num<min?num:min;
        for(int num:nums) res+=num-min;
        return res;
    }
};
