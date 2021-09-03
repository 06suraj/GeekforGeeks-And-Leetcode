void deleteNode(Node *node)
{
   // Your code here
   Node*temp=node->next;
   node->data=node->next->data;
   node->next=node->next->next;
   free(temp);
}
