class Solution {
public:
    int n;
    set<vector<int>> ans;
    vector<int> tmp;
    vector<int> vis;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<int> t(n,0);
        vis.resize(n);
        vis = t;
        dfs(nums);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
    void dfs(vector<int>& nums){
        if(tmp.size()==n){
            ans.insert(tmp);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i] = 1;
                tmp.push_back(nums[i]);
                dfs(nums);
                vis[i] = 0;
                tmp.pop_back(); 
            }
        }
    }
};
