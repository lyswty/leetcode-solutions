class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()) return false;
        unordered_map<char,int>mp;
        for(char x:ransomNote) mp[x]++;
        int cnt=mp.size();
        for(char x:magazine) if(mp.find(x)!=mp.end()){
            mp[x]--;
            if(mp[x]==0){
                cnt--;
                if(cnt==0) return true;
            }
        }
        return !cnt;
    }
};
