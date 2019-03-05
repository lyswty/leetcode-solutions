class Solution {
public:
    void DFS(vector<int>&nums,vector<int>&cur,int i,set<vector<int>>&s){
        cur.push_back(nums[i]);
        s.insert(cur);
        for(int j=i+1;j<nums.size();j++){
            DFS(nums,cur,j,s);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        vector<int>cur;
        s.insert(cur);
        for(int i=0;i<nums.size();i++){
            DFS(nums,cur,i,s);
            cur.pop_back();
        }
        return vector<vector<int>>(s.begin(),s.end());
    }
};
