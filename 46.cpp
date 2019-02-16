class Solution {
public:
    vector<vector<int>>out;
    void p(vector<int>nums,int x,vector<int>&v,int n){
        v.push_back(x);
        if(v.size()==n) out.push_back(v);
        for(int i=0;i<nums.size();i++){
            int y=nums[i];
            vector<int>ns=nums;
            ns.erase(ns.begin()+i);
            p(ns,y,v,n);
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            vector<int>n=nums;
            n.erase(n.begin()+i);
            p(n,x,v,nums.size());
            v.pop_back();
        }
        return out;
    }
};

//各种erase和vector赋值太蠢了- -虽然算法一样，但是速度太慢，下面是别人的代码
/*
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<int> vis;

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> t(n,0);
        vis.resize(n);
        vis = t;
        dfs(nums);
        return ans;
    }
    
    void dfs(vector<int>& nums){
        if(tmp.size()==n){
            ans.push_back(tmp);
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
*/
