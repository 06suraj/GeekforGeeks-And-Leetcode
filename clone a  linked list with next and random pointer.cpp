/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

//Function to clone a linked list with next and random pointer.
Node *copyList(Node *head) {
    Node*cur=head;
    while(cur!=0)  // MAKE THE COPY OF EACH NODE 
    {
        Node*temp=cur->next;
        Node*copy=new Node(cur->data);
        cur->next=copy;
        copy->next=temp;
        cur=temp;
    }
    cur=head;
    while(cur)
    {
        cur->next->arb=cur->arb?cur->arb->next:cur->arb;  // adding the arbitary pointer in copy linked list
        cur=cur->next->next;
    }
    Node*original =head;
    Node*copy=head->next,*result=head->next;
    while(original and copy)  // SEPARATED THE LINKING BETWEEN ORIGINAL AND  CLONE LINKED LIST
    {
        original->next=original->next?original->next->next:original->next;
        copy->next=copy->next?copy->next->next:copy->next;
        original=original->next;
        copy=copy->next;
    }
    return result;
    //  O(N) TIME  AND O(1) SPACE
    // Your code here
}
