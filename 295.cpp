class MedianFinder {
private:
    multiset<int>s1,s2;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s1.empty()) s1.insert(num);
        else{
            auto mid=s1.end();
            mid--;
            if(num<=*mid){
                if(s1.size()>s2.size()){
                    s2.insert(*mid);
                    s1.erase(mid);
                }
                s1.insert(num);
            }
            else{
                s2.insert(num);
                if(s1.size()<s2.size()){
                    s1.insert(*s2.begin());
                    s2.erase(s2.begin());
                }
            }
        }
    }
    
    double findMedian() {
        double res;
        auto mid1=s1.end();
        mid1--;
        if(s1.size()==s2.size()){
            auto mid2=s2.begin();
            res=((double)*mid1+*mid2)/2;
        }
        else res=*mid1;
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
