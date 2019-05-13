class SummaryRanges {
private:
    set<int>s;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        s.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>res;
        auto it=s.begin();
        int start=-2,end=-2;
        while(it!=s.end()){
            if(*it-end>1){
                if(start>=0){
                    vector<int>cur;
                    cur.push_back(start);
                    cur.push_back(end);
                    res.push_back(cur);
                }
                start=*it;
                end=*it;
            }
            else end=*it;
            it++;
        }
        vector<int>cur;
        cur.push_back(start);
        cur.push_back(end);
        res.push_back(cur);
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
