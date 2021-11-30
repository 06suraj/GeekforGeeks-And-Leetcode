/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode*root,int&s){
        if(!root)return;
       if((root->val)%2==0){
           if(root->left){
              if(root->left->left)s+=root->left->left->val;
              if(root->left->right)s+=root->left->right->val;
          }
          if(root->right){
               if(root->right->left)s+=root->right->left->val;
                if(root->right->right)s+=root->right->right->val;
          }
       }
     
      solve(root->left,s);
      solve(root->right,s);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int s=0;
        solve(root,s);
        return s;
    }
};
