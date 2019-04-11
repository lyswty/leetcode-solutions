//这答案没看懂……自己用暴力法最后一个必然TLE
class Solution {
public:
    string shortestPalindrome(string s) {
        int i=0;
        for(int j=s.size()-1;j>-1;j--) if(s[i]==s[j]) i++;
        if(i==s.size()) return s;
        string tmp=s.substr(i);
        reverse(tmp.begin(),tmp.end());
        return tmp+shortestPalindrome(s.substr(0,i))+s.substr(i);
    }
};
