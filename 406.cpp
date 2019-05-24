class Solution {
public:
    static bool cmp(const vector<int> &a,const vector<int> &b){
        if(a[0]!=b[0]) return a[0]>b[0];
        return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        deque<vector<int>>res;
        for(int i=0;i<people.size();i++){
            if(people[i][1]!=i){
                auto x=people[i];
                res.insert(res.begin()+x[1],x);
            }
            else res.push_back(people[i]);
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
};
