class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>father,cnt;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(cnt[nums[i]]) continue;
            else{
                father[nums[i]]=nums[i];
                cnt[nums[i]]++;
            }
            if(cnt[nums[i]-1]){
                int f=nums[i]-1;
                while(father[f]!=f) f=father[f];
                cnt[nums[i]]+=cnt[f];
                father[f]=nums[i];
            }
            if(cnt[nums[i]+1]){
                int f=nums[i]+1;
                while(father[f]!=f) f=father[f];
                cnt[nums[i]]+=cnt[f];
                father[f]=nums[i];
            }
            if(cnt[nums[i]]>max) max=cnt[nums[i]];
        }
        return max;
    }
};
