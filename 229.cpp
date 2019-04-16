class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x=0,y=1,cx=0,cy=0,cnt=0;
        vector<int>res;
        for(int num:nums){
            if((num==x||!cx)&&num!=y){
                cx++;
                x=num;
            }
            else if(num==y||!cy){
                cy++;
                y=num;
            }
            else cx--,cy--;
        }
        for(int num:nums) if(num==x) cnt++;
        if(cnt>nums.size()/3) res.push_back(x);
        cnt=0;
        for(int num:nums) if(num==y) cnt++;
        if(cnt>nums.size()/3) res.push_back(y);
        return res;
    }
};
