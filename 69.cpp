class Solution {
public:
    int mySqrt(int x) {
        if(!x||x==1) return x;
        int out;
        for(out=min(x/2,46340);out*out>x;out--);
        return out;
    }
};
