class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_multiset<char>s;
        int A=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) A++;
            s.insert(secret[i]);
        }
        for(char x:guess){
            auto it=s.find(x);
            if(it!=s.end()) s.erase(it);
        }
        string res=to_string(A);
        res+='A';
        res+=to_string(secret.size()-s.size()-A);
        res+='B';
        return res;
    }
};
