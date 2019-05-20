class Solution {
public:
    int lastRemaining(int n) {
        int start=1,end=n,step=1,cnt=1;
        while(start<end){
            int count=(end-start)/step+1;
            if(cnt++%2){
                start+=step;
                if(count%2) end-=step;
            }
            else{
                if(count%2) start+=step;
                end-=step;
            }
            step*=2;
        }
        return start;
    }
};
