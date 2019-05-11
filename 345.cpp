class Solution {
public:
    bool isvowel(char a){
        return a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U';
    }
    string reverseVowels(string s) {
        if(s.size()<=1) return s;
        int j=s.size()-1;
        while(j>=0&&!isvowel(s[j])) j--;
        string res;
        for(char x:s){
            if(isvowel(x)){
                res+=s[j];
                while(--j>=0&&!isvowel(s[j]));
            }
            else res+=x;
        }
        return res;
    }
};
