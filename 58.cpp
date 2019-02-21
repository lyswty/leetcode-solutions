class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string cur;
        while(ss>>cur);
        return cur.size();
    }
};
