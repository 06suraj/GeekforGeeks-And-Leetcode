/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*T.C=O(n*max(L,h)) , S.C=O(n+L) where n= total number of nodes, L=length of linked list and h is maximum height of tree , we have to check for each node , whether starting from this node , we can get the linked list or not , 
    this can be further optimised to O(n+L) by using KMP search algo */
    
    bool solve(ListNode*head,TreeNode*root,ListNode*originalHead){
        if(!head)return true;
        if(!root)return false;
        ListNode*next=head;
        if(root->val==head->val)next=head->next;
        else if(root->val==originalHead->val)next=originalHead->next;
        else next=originalHead;
        bool l=solve(next,root->left,originalHead);
        bool r=solve(next,root->right,originalHead);
       if(l or r)return true;
       return false;
    }
   
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)return true;
        if(!root)return false;
        bool ans=solve(head,root,head);
        if(ans)return true;
        bool l=isSubPath(head,root->left);
        bool r=isSubPath(head,root->right);
        if(l or r)return true;
        return false;
    }
};
