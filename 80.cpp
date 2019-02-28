class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dupcnts=1;
        if(nums.size()<3) return nums.size();
        for(auto it=nums.begin()+1;it!=nums.end();it++){
            if(*it==*(it-1)){
                if(dupcnts==2) {
                    it=nums.erase(it);
                    it--;
                }
                else dupcnts++;
            }
            else dupcnts=1;
        }
        return nums.size();
    }
};
