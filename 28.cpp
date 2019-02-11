class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
        /*
        if(!needle.size()) return 0;
        int flag=1;
        for(int i=0;i+needle.size()-1<haystack.size();i++){
            flag=1;
            for(int j=0;j<needle.size();j++) if(needle[j]!=haystack[i+j]){
                flag=0;
                break;
            }
            if(flag) return i;
        }
        return -1;
        */
    }
};
