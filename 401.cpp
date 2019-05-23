class Solution {
public:
    int count1(int n){
        int res=0;
        while(n){
            n&=n-1;
            res++;
        }
        return res;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string>res;
        for(int i=0;i<12;i++) for(int j=0;j<60;j++){
            if(count1(i)+count1(j)==num){
                stringstream ss;
                ss<<i<<':'<<setfill('0')<<setw(2)<<j;
                res.push_back(ss.str());
            } 
        }
        return res;
    }
};
