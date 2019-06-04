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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1=0,length2=0;
        ListNode* res=NULL;
        for(auto p1=l1;p1;p1=p1->next) length1++;
        for(auto p2=l2;p2;p2=p2->next) length2++;
        if(length1>length2) res=add(l1,l2,length1-length2);
        else res=add(l2,l1,length2-length1);
        if(res->val>9){
            ListNode* head=new ListNode(1);
            head->next=res;
            res->val-=10;
            res=head;
        }
        return res;
    }
    ListNode* add(ListNode* l1,ListNode* l2,int n){
        if(!l1) return NULL;
        else{
            ListNode* cur=NULL;
            if(n){
                cur=new ListNode(l1->val);
                cur->next=add(l1->next,l2,n-1);
            }
            else{
                cur=new ListNode(l1->val+l2->val);
                cur->next=add(l1->next,l2->next,0);
            }
            if(cur->next&&cur->next->val>9){
                cur->val++;
                cur->next->val-=10;
            }
            return cur;
        }
    }
};
