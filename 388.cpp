class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int>s;
        int chrlen=0,tablen=0,longest=0;
        bool isFile=false;
        input+="\n";
        for(char ch:input){
            if(ch=='\n'){
                while(s.size()>tablen) s.pop();
                int len=(s.size()?s.top()+1:0)+chrlen;
                if(isFile){
                    if(len>longest) longest=len;
                }
                else s.push(len);
                chrlen=tablen=isFile=0;
            }
            else if(ch=='\t') tablen++;
            else{
                if(ch=='.') isFile=true;
                chrlen++;
            }
        }
        return longest;
    }
};
