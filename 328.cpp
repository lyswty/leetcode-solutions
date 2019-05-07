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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next) return head;
        auto ptr=head;
        ListNode* end;
        int cnt=2;
        for(end=head->next;end->next;end=end->next,cnt++);
        cnt/=2;
        while(cnt--){
            end->next=ptr->next;
            ptr->next=ptr->next->next;
            ptr=ptr->next;
            end=end->next;
            end->next=NULL;
        }
        return head;
    }
};
