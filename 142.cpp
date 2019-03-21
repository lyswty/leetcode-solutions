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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return NULL;
        bool hascycle=false;
        ListNode *ptr1=head->next,*ptr2=head->next->next;
        while(ptr1&&ptr2&&ptr2->next){
            if(ptr1==ptr2){
                hascycle=true;
                break;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next->next;
        }
        if(!hascycle) return NULL;
        ListNode* ptr3=head;
        while(ptr3!=ptr1){
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }
        return ptr1;
    }
};
