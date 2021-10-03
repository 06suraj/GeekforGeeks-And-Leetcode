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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prev=0,*cur,*inter ,*head;
        
        if(!l1 and !l2)return 0;
        else if(!l1)return l2;
        else if(!l2)return l1;
        
        if(l1->val<=l2->val)head=l1,cur=l1->next,prev=l1,inter=l2;
        else head=l2,cur=l2->next,prev=l2,inter=l1;
        
        while(cur and inter){
            if(inter->val>=prev->val and inter->val<=cur->val){
                ListNode*temp;
                temp=inter;
                 inter=inter->next;
                prev->next=temp;
                temp->next=cur;
                prev=prev->next;
            }
            else{
                cur=cur->next;
                prev=prev->next;
            }
        }
        if(inter)prev->next=inter;
        return head;
        
    }
};
