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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL&&n==1){
            delete head;
            return NULL;
        }
        ListNode *first=NULL,*second=NULL;
        first=head,second=head;
        for(int i=0;i<n;i++) first=first->next;
        if(first) {
            first=first->next;
            while(first!=NULL){
                first=first->next;
                second=second->next;
            }
            first=second->next;
            second->next=first->next;
            delete first;
        }
        else{
            head=head->next;
            delete second;
        }
        return head;
    }
};
