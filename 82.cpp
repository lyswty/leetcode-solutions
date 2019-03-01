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
    ListNode* deleteDuplicates(ListNode* head) {
        int del=INT_MIN;
        while(head&&head->next&&head->val==head->next->val){
            del=head->val;
            while(head){
                if(head->val==del){
                    auto d1=head;
                    head=head->next;
                    delete d1;
                }
                else break;
            }
        }
        for(ListNode* i=head;i;){
            if(i->next&&i->next->next&&i->next->val==i->next->next->val){
                del=i->next->val;
                auto d1=i->next;
                i->next=d1->next->next;
                delete d1->next;
                delete d1;
            }
            else if(i->next&&i->next->val==del){
                auto d1=i->next;
                i->next=d1->next;
                delete d1;
            }
            else i=i->next;
        }
        return head;
    }
};
