//Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class Solution {
  public:
  int cnt;
  int solve(Node*root){
      if(root==0)return 0;
      if(root->left==0 and root->right==0){cnt++;return root->data;}
      int l=solve(root->left);
      int r=solve(root->right);
      if(root->left and root->right){
          if(l==r and r==root->data)
          {
              cnt++;
              return root->data;
          }else return INT_MAX;
      }
      else if(root->left){
          if(l==root->data)
          {
              cnt++;
              return root->data;
          }else return INT_MAX;
      }else {
          if(r==root->data){
              cnt++;
              return root->data;
          }
          else return INT_MAX;
      }
  }
    int countSubtrees(Node* root)
    {
        // Your code goes here
        cnt=0;
        solve(root);
        return cnt;
    }
};
