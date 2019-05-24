class Solution {
public:
    string toHex(int num) {
        char trans[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string res;
        while(num&&res.size()<8){
            res=trans[num&0xf]+res;
            num>>=4;
        }
        if(res.empty()) return "0";
        return res;
    }
};
