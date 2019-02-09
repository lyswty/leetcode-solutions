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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3=NULL;
        if(l1&&l2){
            if(l1->val<l2->val){
                l3=new ListNode(l1->val);
                l3->next=mergeTwoLists(l1->next,l2);
            }
            else{
                l3=new ListNode(l2->val);
                l3->next=mergeTwoLists(l1,l2->next);
            }
        }
        else if(l1){
            l3=new ListNode(l1->val);
            l3->next=mergeTwoLists(l1->next,NULL);
        }
        else if(l2){
            l3=new ListNode(l2->val);
            l3->next=mergeTwoLists(NULL,l2->next);
        }
        return l3;
    }
};
