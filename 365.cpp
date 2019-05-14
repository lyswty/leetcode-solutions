class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(!z) return true;
        if(x+y<z) return false;
        if(!x&&!y) return false;
        if(!x) return y==z;
        if(!y) return x==z;
        if(x<y) swap(x,y);
        while(x%y){
            int a=x%y;
            x=y;
            y=a;
        }
        return z%y==0;
    }
};
