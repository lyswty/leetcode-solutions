class Solution {
public:
    bool isPalindrome(int x) {
        int a=x,b=0;
        if(a<0) return false;
        else if(!a) return true;
        while(a>0){
            b*=10;
            b+=a%10;
            a/=10;
        }
        if(x==b) return true;
        else return false;
    }
};
