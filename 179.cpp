class Solution {
public:
    static bool cmp(const string &a,const string &b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>n(nums.size());
        for(int i=0;i<nums.size();i++) n[i]=to_string(nums[i]);
        sort(n.begin(),n.end(),cmp);
        string res;
        for(int i=0;i<nums.size();i++) res+=n[i];
        for(int i=0;i<res.size();i++){
            if(res[i]!='0'||i+1==res.size()){
                res=res.substr(i);
                break;
            }
        }
        return res;
    }
};
