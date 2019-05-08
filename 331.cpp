class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=1;
        string str;
        stringstream ss(preorder);
        while(getline(ss,str,',')){
            --n;
            if(n<0) return false;
            if(str!="#") n+=2;
        }
        return !n;
    }
};
