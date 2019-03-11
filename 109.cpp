/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* create(ListNode* head,ListNode* end){
        if(head==end) return NULL;
        ListNode* ptr1,*ptr2;
        for(ptr1=head,ptr2=head;ptr2->next!=end&&ptr2->next->next!=end;ptr1=ptr1->next,ptr2=ptr2->next->next);
        TreeNode* root=new TreeNode(ptr1->val);
        root->left=create(head,ptr1);
        root->right=create(ptr1->next,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return create(head,NULL);
    }
};
