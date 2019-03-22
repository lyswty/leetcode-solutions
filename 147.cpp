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
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next) return head;
        auto ptr=head,p=head->next;
        int last=head->val;
        while(p){
            if(p->val<last){
                auto ne=p->next;
                if(p->val<=head->val){
                    p->next=head;
                    head=p;
                    ptr->next=ne;
                    p=ne;
                }
                else{
                    auto ptr1=head,ptr2=head->next;
                    while(ptr2->val<p->val){
                        ptr1=ptr1->next;
                        ptr2=ptr2->next;
                    }
                    ptr1->next=p;
                    p->next=ptr2;
                    ptr->next=ne;
                    p=ne;
                }
            }
            else{
                last=p->val;
                ptr=ptr->next;
                p=p->next;
            }
        }
        return head;
    }
};
