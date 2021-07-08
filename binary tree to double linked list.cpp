class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* head=0;
    Node* previous=0;
    bool f=0;
    void solve(Node*root)
    {
        if(!root)return ;
        solve(root->left);
        if(f==0)
        {
            head=root;
            previous=root;
            f=1;
        }
        else
        {
            previous->right=root;
            root->left=previous;
            previous=root;
        }
        solve(root->right);
    }
        
        Node * bToDLL(Node *root)
        {
            // your code here
        head=0,previous=0,f=0;
        solve(root);
        return head;
        }
};
