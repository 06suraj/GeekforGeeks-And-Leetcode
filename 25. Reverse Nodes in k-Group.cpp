/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode*curr_node=head,*next_node=head,*prev_node=0,*start=0,*end=0;
    if(head==0||head->next==0||k<=0)
    return head;
    int i=0,sub=0,sub1=0;
    while(curr_node!=0)
    {curr_node=curr_node->next,sub1++;}
    sub=sub1/k;
    curr_node=head;
    
    while(curr_node!=0&&sub>0)
    {
        i=0;
        prev_node=0;
        start=curr_node;
        while(sub>=0&&curr_node!=0&&i<k)
        {
            next_node=next_node->next;
            curr_node->next=prev_node;
            prev_node=curr_node;
            curr_node=next_node;
            i++;
        }
        sub--;
        if(sub==(sub1/k-1))
        head=prev_node;
        else 
        {
            
            end->next=prev_node;
           
        }
        end=start;
    }
    start->next=curr_node;
    return head;


}
