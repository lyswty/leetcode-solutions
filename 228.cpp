class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        if(nums.empty()) return res;
        if(nums.size()==1){
            res.push_back(to_string(nums[0]));
            return res;
        }
        int start=nums[0],end=start;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]+1){
                end=nums[i-1];
                if(end==start) res.push_back(to_string(start));
                else{
                    string cur=to_string(start);
                    cur+="->";
                    cur+=to_string(end);
                    res.push_back(cur);
                }
                start=nums[i];
            }
            if(i+1==nums.size()){
                end=nums[i];
                if(end==start) res.push_back(to_string(start));
                else{
                    string cur=to_string(start);
                    cur+="->";
                    cur+=to_string(end);
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};
