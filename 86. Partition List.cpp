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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode*small,*large,*smallhead=0,*largehead=0,*curr=head;
        while(curr){
            ListNode*temp=curr->next;
            curr->next=0;
            if(curr->val<x){
                if(smallhead==0)smallhead=curr,small=curr;
                else small->next=curr,small=small->next;
            }else{
                if(largehead==0)largehead=curr,large=curr;
                else large->next=curr,large=large->next;
            }
            curr=temp;
        }
        if(smallhead==0)return largehead;
        small->next=largehead;
        return smallhead;
        
    }
};
