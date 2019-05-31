class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        list<vector<int>> l(intervals.begin(),intervals.end());
        auto it=l.begin();
        int res=0;
        for(it++;it!=l.end();it++){
            auto it2=it;
            it2--;
            if((*it)[0]<(*it2)[1]){
                if((*it)[1]>(*it2)[1]){
                    it=l.erase(it);
                    it--;
                }
                else l.erase(it2);
                res++;
            }
        }
        return res;
    }
};
