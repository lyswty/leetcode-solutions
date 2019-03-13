/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left&&root->right) root->left->next=root->right;
        if(root->next){
            Node* lptr=root->right?root->right:root->left;
            if(lptr){
                auto r=root->next;
                while(r&&!r->left&&!r->right) r=r->next;
                if(r) lptr->next=r->left?r->left:r->right;
            }
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};
