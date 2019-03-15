class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()<2) return true;
        int i=0,j=s.size()-1;
        while(i<j){
            if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else{
                if(isalpha(s[i])) s[i]=tolower(s[i]);
                if(isalpha(s[j])) s[j]=tolower(s[j]);
                if(s[i]!=s[j]) return false;
                i++,j--;
            }
        }
        return true;
    }
};
