/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& a,const Interval& b){
        if(a.start!=b.start) return a.start<b.start;
        return a.end<b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<2) return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval>out;
        out.reserve(intervals.size());
        for(int i=0;i<intervals.size();i++){
            if(out.empty()||out[out.size()-1].end<intervals[i].start) out.push_back(intervals[i]);
            else if(out[out.size()-1].end<intervals[i].end) out[out.size()-1].end=intervals[i].end;
        }
        return out;
    }
};
