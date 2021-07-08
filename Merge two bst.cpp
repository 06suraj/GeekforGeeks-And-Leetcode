class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node*root,vector<int>&t)
{
    if(root==0)return;
    inorder(root->left,t);
    t.push_back(root->data);
    inorder(root->right,t);
}
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
    vector<int>a,b;
   inorder(root1,a);
   inorder(root2,b);
   for(int i=0;i<b.size();i++)
   a.push_back(b[i]);
   sort(a.begin(),a.end());
   return a;
    }
};
