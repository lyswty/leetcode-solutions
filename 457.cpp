class Solution {
public:
    int next(vector<int>& nums,int i){
        i+=nums[i];
        int n=nums.size();
        while(i<0) i+=n;
        return i%n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int fast=i,slow=i;
            bool positive=true,con=false;
            if(nums[i]<0) positive=false;
            do{
                if(next(nums,slow)==slow||next(nums,fast)==fast||next(nums,next(nums,fast))==next(nums,fast)||positive&&(nums[slow]<0||nums[fast]<0||nums[next(nums,fast)]<0)||!positive&&(nums[slow]>0||nums[fast]>0||nums[next(nums,fast)]>0)){
                    con=true;
                    break;
                }
                slow=next(nums,slow);
                fast=next(nums,fast);
                fast=next(nums,fast);
            }while(slow!=fast);
            if(next(nums,slow)==slow||next(nums,fast)==fast||next(nums,next(nums,fast))==next(nums,fast)||positive&&(nums[slow]<0||nums[fast]<0||nums[next(nums,fast)]<0)||!positive&&(nums[slow]>0||nums[fast]>0||nums[next(nums,fast)]>0)) con=true;
            if(!con&&slow==fast) return true;
        }
        return false;
    }
};
