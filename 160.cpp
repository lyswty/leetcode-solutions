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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p=headA,q=headB;
        if(!p||!q) return NULL;
        while(p->next&&q->next){
            p=p->next;
            q=q->next;
        }
        int cnt=0;
        while(p->next){
            p=p->next;
            cnt++;
        }
        while(q->next){
            q=q->next;
            cnt--;
        }
        if(p!=q) return NULL;
        p=headA,q=headB;
        while(cnt>0){
            p=p->next;
            cnt--;
        }
        while(cnt<0){
            q=q->next;
            cnt++;
        }
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        return p;
    }
};
