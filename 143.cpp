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
    ListNode* reverse(ListNode* head){
        ListNode *p1=NULL,*p2=head,*p3=head;
        while(p2){
            p3=p2->next;
            p2->next=p1;
            p1=p2;
            p2=p3;
        }
        return p1;
    }
    void reorderList(ListNode* head) {
        if(!head||!head->next) return;
        ListNode *p1=head,*p2=head;
        while(p2->next&&p2->next->next){
            p1=p1->next;
            p2=p2->next->next;
        }
        ListNode* l2=p1->next;
        p1->next=NULL;
        l2=reverse(l2);
        ListNode* l1=head;
        while(l1&&l2){
            ListNode* x=l2->next;
            l2->next=l1->next;
            l1->next=l2;
            l1=l2->next;
            l2=x;
        }
    }
};
