class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int MAX=INT_MIN,MIN=INT_MAX,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<MIN) MIN=nums[i];
            if(nums[i]>MAX) MAX=nums[i];
        }
        int width=(MAX-MIN)/nums.size()+1;
        vector<pair<int,int>>drums((MAX-MIN)/width+1,pair<int,int>(INT_MAX,-1));
        for(int i=0;i<nums.size();i++){
            int dnum=(nums[i]-MIN)/width;
            if(nums[i]>drums[dnum].second) drums[dnum].second=nums[i];
            if(nums[i]<drums[dnum].first) drums[dnum].first=nums[i];
        }
        for(int i=0;i<(MAX-MIN)/width+1;i++){
            if(drums[i].second==-1) continue;
            int j=i+1;
            while(j<(MAX-MIN)/width+1&&drums[j].second==-1) j++;
            if(j==(MAX-MIN)/width+1) break;
            if(drums[j].first-drums[i].second>res) res=drums[j].first-drums[i].second;
        }
        return res;
    }
};
