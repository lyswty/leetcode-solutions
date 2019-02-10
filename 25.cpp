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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *a=head;
        int cnt=0;
        while(a){
            a=a->next;
            cnt++;
        }
        if(cnt<k) return head;
        a=head;
        ListNode *b=a->next;
        for(int i=0;i<k-1;i++){
            ListNode *c=b->next;
            b->next=a;
            a=b;
            b=c;
        }
        head->next=reverseKGroup(b,k);
        return a;
    }
};
