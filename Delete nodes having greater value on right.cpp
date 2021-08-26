struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node*reverse(Node*head)
{
    Node*prev=0;
    while(head!=0)
    {
        Node*temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    head=prev;
    return head;
}
Node *compute(Node *head)
{
    // your code goes here
    head=reverse(head);
    Node*temp=head,*prev=head;
    int ma=head->data;
    while(head!=0)
    {
        if(head->data<ma)
        {
            Node*de=prev->next;
            prev->next=head->next;
            head=head->next;
            free(de);
        }
        else 
        {
            ma=head->data;
            prev=head;
            head=head->next;
        }
        
    }
    head=reverse(temp);
    return head;
    
}
