class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string x;
        int res=0;
        while(ss>>x) res++;
        return res;
    }
};
