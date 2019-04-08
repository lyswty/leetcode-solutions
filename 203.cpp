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
    ListNode* removeElements(ListNode* head, int val) {
        while(head&&head->val==val){
            auto p=head->next;
            delete head;
            head=p;
        }
        if(!head) return head;
        auto last=head,cur=head->next;
        while(cur){
            if(cur->val==val){
                last->next=cur->next;
                delete cur;
                cur=last->next;
            }
            else{
                last=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};
