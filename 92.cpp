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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n||!head||!head->next) return head;
        ListNode* before=NULL,*start=head,*end=head->next,*ptr=head;
        for(int i=2;i<=m;i++){
            if(i==2) before=head;
            else before=before->next;
        }
        if(m>1) start=before->next;
        ptr=start,end=ptr->next;
        for(int i=m;i<n;i++){
            ListNode* x=end->next;
            end->next=ptr;
            ptr=end;
            end=x;
        }
        if(before) before->next=ptr;
        start->next=end;
        if(before) return head;
        else return ptr;
    }
};
