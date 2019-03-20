/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*,Node*>mp;
        Node* last=NULL;
        for(auto ptr=head;ptr!=NULL;ptr=ptr->next){
            if(!mp[ptr]) mp[ptr]=new Node(ptr->val,NULL,NULL);
            if(last) last->next=mp[ptr];
            last=mp[ptr];
            if(ptr->random&&mp[ptr->random]) mp[ptr]->random=mp[ptr->random];
            else if(ptr->random&&!mp[ptr->random]){
                mp[ptr->random]=new Node(ptr->random->val,NULL,NULL);
                mp[ptr]->random=mp[ptr->random];
            }
        }
        return mp[head];
    }
};
