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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        auto it=head;
        while(it->next){
            if(it->val==it->next->val){
                auto del=it->next;
                it->next=del->next;
                delete del;
            }
            else it=it->next;
        }
        return head;
    }
};
