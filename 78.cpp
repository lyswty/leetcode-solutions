class Solution {
public:
    void DFS(vector<vector<int>>&out,vector<int>&cur,vector<int>&nums,int i){
        cur.push_back(nums[i]);
        out.push_back(cur);
        for(int j=i+1;j<nums.size();j++){
            DFS(out,cur,nums,j);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        vector<vector<int>>out;
        out.push_back(cur);
        for(int i=0;i<nums.size();i++){
            DFS(out,cur,nums,i);
            cur.pop_back();
        }
        return out;
    }
};
