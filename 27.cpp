class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        for(auto it=nums.begin();it!=nums.end();it++){
            if(*it==val){
                it=nums.erase(it);
                it--;
            }
            else cnt++;
        }
        return cnt;
    }
};
