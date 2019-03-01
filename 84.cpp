class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max=0;
        for(int i=0;i<heights.size();i++){
            int left=i,right=i;
            bool l=true,r=true;
            while(l||r){
                if(l){
                    left--;
                    if(left<0||heights[left]<heights[i]) l=false;
                }
                if(r){
                    right++;
                    if(right==heights.size()||heights[right]<heights[i]) r=false;
                }
            }
            if((right-left-1)*heights[i]>max) max=(right-left-1)*heights[i];
        }
        return max;
    }
};
