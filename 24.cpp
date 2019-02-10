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
    ListNode* swapPairs(ListNode* head) {
        ListNode* out,*last=NULL;
        if(head&&head->next) out=head->next;
        else out=head;
        while(head&&head->next){
            ListNode* ptr=head->next;
            head->next=ptr->next;
            ptr->next=head;
            if(last) last->next=ptr;
            last=head;
            head=head->next;
        }
        return out;
    }
};
