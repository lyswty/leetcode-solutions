class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string cur,out;
        while(ss>>cur){
            if(out.empty()) out=cur;
            else{
                cur+=' ';
                out=cur+out;
            }
        }
        return out;
    }
};
