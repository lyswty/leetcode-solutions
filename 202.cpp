class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1){
            int next=0;
            while(n){
                next+=(n%10)*(n%10);
                n/=10;
            }
            if(s.find(next)!=s.end()) return false;
            s.insert(next);
            n=next;
        }
        return true;
    }
};
