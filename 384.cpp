class Solution {
private:
    vector<int>data,start;
public:
    Solution(vector<int>& nums) {
        data=nums;
        start=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        data=start;
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(data.empty()) return data;
        for(int i=data.size();i>0;i--){
            int inx=rand()%i;
            swap(data[inx],data[i-1]);
        }
        return data;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
