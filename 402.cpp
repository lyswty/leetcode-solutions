class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char>s;
        string res;
        for(int i=0;i<num.size();i++){
            while(s.size()&&s.back()>num[i]&&k>0){
                s.pop_back();
                k--;
            }
            if(num[i]!='0'||s.size()!=0) s.push_back(num[i]);
        }
        while(s.size()&&k>0){
            s.pop_back();
            k--;
        }
        for(int i=0;i<s.size();i++) res+=s[i];
        if(res.empty()) res="0";
        return res;
    }
};
