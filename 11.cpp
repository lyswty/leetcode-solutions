class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,max=0;
        while(i<j){
            int cur=min(height[i],height[j])*(j-i);
            if(max<cur) max=cur;
            height[i]<height[j]?i++:j--;
        }
        return max;
    }
};
