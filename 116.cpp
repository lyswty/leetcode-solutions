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
        Node* T=root;
        if(!T) return root;
        queue<Node*>s;
        s.push(T);
        Node *last=root,*l=NULL;
        while(s.size()){
            T=s.front();
            s.pop();
            if(T->left){
                s.push(T->left);
                if(l) l->next=T->left;
                s.push(T->right);
                T->left->next=T->right;
                l=T->right;
            }
            else break;
            if(T==last){
                last=l;
                l=NULL;
            }
        }
        return root;
    }
};
