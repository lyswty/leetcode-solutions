/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<ListNode*>v;
        for(ListNode* ptr=head;ptr;ptr=ptr->next) v.push_back(ptr);
        if(v.empty()||k%v.size()==0) return head;
        v[v.size()-1]->next=v[0];
        v[v.size()-k%v.size()-1]->next=NULL;
        return v[v.size()-k%v.size()];
    }
};
