/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node*curr,*temp,*head=0,*prev;
        temp=root;
        while(root){
            head=root,prev=0;
            while(head){
                if(head->left){
                    if(prev==0)prev=head->left;
                    else prev->next=head->left;
                    prev=head->left;
                }
                if(head->right){
                    if(prev==0)prev=head->right;
                    else prev->next=head->right;
                    prev=head->right;
                }
                head=head->next;
            }
            while(root and root->left==0 and root->right==0)root=root->next;
            if(root and root->left)root=root->left;
            else if(root)root=root->right;
        }
        return temp;
    }
};
