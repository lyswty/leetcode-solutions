//感觉还有一点可以优化的地方，寻找插入位点的时候可以用二分查找，然后直接对原数组进行改动- -

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>out;
        bool alreadyinsert=false;
        out.reserve(intervals.size()+1);
        for(int i=0;i<intervals.size();i++){
            if(intervals[i].end<newInterval.start) out.push_back(intervals[i]);
            else if(intervals[i].start>newInterval.end){
                if(!alreadyinsert){
                    out.push_back(newInterval);
                    alreadyinsert=true;
                }
                out.push_back(intervals[i]);
            }
            else{
                newInterval.start=min(intervals[i].start,newInterval.start);
                newInterval.end=max(intervals[i].end,newInterval.end);
            }
        }
        if(!alreadyinsert){
            out.push_back(newInterval);
            alreadyinsert=true;
        }
        return out;
    }
};
