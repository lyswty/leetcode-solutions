class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first=LONG_MIN,second=LONG_MIN,third=LONG_MIN;
        for(int i:nums){
            if(i==first||i==second||i==third) continue;
            if(i>first){
                third=second;
                second=first;
                first=i;
            }
            else if(i>second){
                third=second;
                second=i;
            }
            else if(i>third) third=i;
        }
        return third!=LONG_MIN?third:first;
    }
};
