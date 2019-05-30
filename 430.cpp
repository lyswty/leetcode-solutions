/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* ptr=head;
        while(ptr){
            if(ptr->child){
                Node* tmp=ptr->child;
                while(tmp->next) tmp=tmp->next;
                tmp->next=ptr->next;
                if(tmp->next) tmp->next->prev=tmp;
                ptr->next=ptr->child;
                ptr->next->prev=ptr;
                ptr->child=NULL;
            }
            ptr=ptr->next;
        }
        return head;
    }
};
