/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*>s;
    void pushstack(TreeNode* T){
        if(!T) return;
        while(T){
            s.push(T);
            T=T->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushstack(root);
    }
    
    /** @return the next smallest number */
    int next() {
        auto T=s.top();
        s.pop();
        pushstack(T->right);
        return T->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
