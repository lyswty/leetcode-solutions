class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,out=0;
        while(i+1<height.size()){
            if(height[i]>0){
                int max=-1,maxj=-1;
                for(int j=i+1;j<height.size();j++){
                    if(height[j]>max){
                        max=height[j];
                        maxj=j;
                    }
                    if(height[j]>=height[i]){
                        max=height[i];
                        break;
                    }
                }
                for(int j=i+1;j<maxj;j++) out+=max-height[j];
                i=maxj;
            }
            else i++;
        }
        return out;
    }
};
