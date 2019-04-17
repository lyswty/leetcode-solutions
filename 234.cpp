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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        auto fast=head,slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast) slow=slow->next;
        auto mid=slow,ptr=slow->next;
        ListNode* last=NULL;
        slow->next=last;
        while(ptr){
            last=slow;
            slow=ptr;
            ptr=ptr->next;
            slow->next=last;
        }
        while(slow){
            if(slow->val!=head->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};
