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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](const ListNode* l1, const ListNode* l2){return l1->val>l2->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>q(cmp);
        for(auto it:lists) if(it) q.push(it);
        if(q.size()){ 
            ListNode* head=q.top();
            while(q.size()){
                ListNode* cur=q.top();
                q.pop();
                if(cur->next) q.push(cur->next);
                if(q.size()) cur->next=q.top();
            }
            return head;
        }
        else return NULL;
    }
};
