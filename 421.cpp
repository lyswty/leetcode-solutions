class Solution {
private:
    struct node{
        int val;
        node *left,*right;
        int flag;
        node(int value):val(value),left(NULL),right(NULL),flag(-1){}
    };
    int res,tmp;
public:
    void construct(node* &root,int val,int cnt){
        if(cnt>32){
            root->flag=tmp;
            return;
        }
        if((val>>(32-cnt))&1){
            if(!root->right) root->right=new node(1);
            construct(root->right,val,cnt+1);
        }
        else{
            if(!root->left) root->left=new node(0);
            construct(root->left,val,cnt+1);
        }
    }
    void find(node* root,int val,int cnt){
        if(cnt>32){
            res=max(res,root->flag^tmp);
            return;
        }
        if((val>>(32-cnt))&1){
            if(root->left) find(root->left,val,cnt+1);
            else find(root->right,val,cnt+1);
        }
        else{
            if(root->right) find(root->right,val,cnt+1);
            else find(root->left,val,cnt+1);
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        node* root=new node(0);
        for(int i:nums){
            tmp=i;
            construct(root,i,1);
        }
        for(int i:nums){
            tmp=i;
            find(root,i,1);
        }
        return res;
    }
};
