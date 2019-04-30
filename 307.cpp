//自己造出了线段树的轮子还一把过真的是好开心啊
class NumArray {
private:
    typedef struct Node{
        int val;
        int start,end;
        Node *left,*right;
        Node():left(NULL),right(NULL){}
        Node(int x,int y):val(x),left(NULL),right(NULL),start(y),end(y){}
    }*SegTree;
    SegTree root;
    SegTree build(SegTree root,vector<int>&nums,int start,int end){
        if(start>end) return NULL;
        if(start==end){
            root=new Node(nums[start],start);
            return root;
        }
        int mid=(start+end)/2;
        root=new Node();
        root->left=build(root->left,nums,start,mid);
        root->right=build(root->right,nums,mid+1,end);
        root->val=root->left->val+root->right->val;
        root->start=start;
        root->end=end;
        return root;
    }
    int query(int qstart,int qend,SegTree root){
        if(qstart>root->end||qend<root->start) return 0;
        if(qstart<=root->start&&qend>=root->end) return root->val;
        return query(qstart,qend,root->left)+query(qstart,qend,root->right);
    }
    void updatetree(SegTree root,int i,int val){
        if(i==root->start&&i==root->end) root->val=val;
        else if(i<=root->left->end&&i>=root->left->start){
            int last=root->left->val;
            updatetree(root->left,i,val);
            root->val+=root->left->val-last;
        }
        else if(i<=root->right->end&&i>=root->right->start){
            int last=root->right->val;
            updatetree(root->right,i,val);
            root->val+=root->right->val-last;
        }
    }
public:
    NumArray(vector<int>& nums) {
        root=build(root,nums,0,(int)nums.size()-1);
    }
    
    void update(int i, int val) {
        updatetree(root,i,val);
    }
    
    int sumRange(int i, int j) {
        return query(i,j,root);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
