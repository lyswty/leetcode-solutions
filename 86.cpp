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
    ListNode* partition(ListNode* head, int x) {
        ListNode* last=NULL;
        for(auto ptr=head;ptr&&ptr->next;ptr=ptr->next){
            if(ptr->val<x) last=ptr;
            if(ptr->val>=x&&ptr->next->val<x){
                auto start=ptr->next,end=ptr->next;
                for(;end->next&&end->next->val<x;end=end->next);
                ptr->next=end->next;
                if(!last){
                    end->next=head;
                    head=start;
                }
                else{
                    end->next=last->next;
                    last->next=start;
                }
                last=end;
            }
        }
        return head;
    }
};
