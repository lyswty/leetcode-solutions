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
    ListNode* sortList(ListNode* head) {
        return qsort(head,NULL);
    }
    ListNode* qsort(ListNode* begin,ListNode* end){
        if(begin==end||begin->next==end) return begin;
        auto k=begin,cur=begin->next,ne=begin;
        while(cur!=end){
            if(cur->val<k->val){
                ne->next=cur->next;
                cur->next=begin;
                begin=cur;
                cur=ne->next;
            }
            else{
                ne=ne->next;
                cur=cur->next;
            }
        }
        begin=qsort(begin,k);
        k->next=qsort(k->next,end);
        return begin;
    }
};
