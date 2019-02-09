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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ten=0;
        ListNode *p1=l1,*p2=l2,*p;
        while(p1&&p2){
            p2->val+=p1->val+ten;
            ten=p2->val/10;
            p2->val%=10;
            p1->val=p2->val;
            if(!p1->next&&!p2->next) p=p1;
            p1=p1->next;
            p2=p2->next;
        }
        if(p1){
            while(p1){
                p1->val+=ten;
                ten=p1->val/10;
                p1->val%=10;
                if(!p1->next) p=p1;
                p1=p1->next;
            }
            if(ten) p->next=new ListNode(1);
            return l1;
        }
        else if(p2){
            while(p2){
                p2->val+=ten;
                ten=p2->val/10;
                p2->val%=10;
                if(!p2->next) p=p2;
                p2=p2->next;
            }
            if(ten) p->next=new ListNode(1);
            return l2;
        }
        else if(ten){
            p->next=new ListNode(1);
            return l1;
        }
        else return l1;
    }
};
