class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start=0;
        vector<string>out;
        while(start<words.size()){
            int curlength=0,end=start;
            while(end<words.size()){
                curlength+=words[end].size();
                if(end!=start) curlength++;
                if(curlength>maxWidth){
                    curlength-=words[end].size()+1;
                    break;
                }
                end++;
            }
            string cur;
            if(end==words.size()||end-start==1){
                cur+=words[start];
                for(int i=start+1;i<end;i++){
                    cur+=' ';
                    cur+=words[i];
                }
                for(int i=cur.size();i<maxWidth;i++) cur+=' ';
            }
            else{
                int cnt=(maxWidth-curlength+end-start-1)/(end-start-1),more=(maxWidth-curlength+end-start-1)-cnt*(end-start-1);
                cur+=words[start];
                for(int i=1;i<=more;i++){
                    for(int i=0;i<cnt+1;i++) cur+=' ';
                    cur+=words[start+i];
                }
                for(int i=start+more+1;i<end;i++){
                    for(int i=0;i<cnt;i++) cur+=' ';
                    cur+=words[i];
                }
            }
            out.push_back(cur);
            start=end;
        }
        return out;
    }
};
