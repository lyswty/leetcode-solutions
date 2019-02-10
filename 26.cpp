class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        auto it=nums.begin()+1;
        int n=1;
        while(it!=nums.end()){
            if(*it==*(it-1)) it=nums.erase(it);
            else{
                n++;
                it++;
            }
        }
        return n;
    }
};
