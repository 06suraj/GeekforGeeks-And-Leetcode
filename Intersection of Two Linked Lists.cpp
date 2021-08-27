/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int f=0,s=0,d=0;
   struct ListNode*temp=headA,*temp1=headB;
    while(temp!=0)
    {
        temp=temp->next;
        f++;
    }
   while(temp1!=0)
   {
       temp1=temp1->next;
       s++;
   }
   d=abs(f-s),temp=headA,temp1=headB;
   if(f>s)
   {
       for(int i=0;i<d;i++)
       temp=temp->next;
       while(temp!=temp1)
   {
       temp=temp->next,temp1=temp1->next;
   }
   return temp;
   }else
   {
       for(int i=0;i<d;i++)
       temp1=temp1->next;
       while(temp1!=temp)
   {
       temp=temp->next,temp1=temp1->next;
   }
   return temp1;
   }
   
   
   return 0;
    
}
