/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
 struct ListNode*slow=head,*fast=head;
       int i=0;
       while(i<n)
       {
           if (fast->next == NULL)  
            { 
  
                // If count = N i.e. 
                // delete the head node 
                if (i == n - 1) 
                    head = head->next; 
                return head; 
            } 
           fast=fast->next;
           i++;
       }
    
       while(fast->next!=0)
       {
          
           fast=fast->next,slow=slow->next;
       }
       slow->next=slow->next->next;
    return head;
}
