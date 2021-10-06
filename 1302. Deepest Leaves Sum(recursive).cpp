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
    void solve(TreeNode*root,int h,int&s,int &maxi){
        if(root==0)return ;
       if(root->left==0 and root->right==0){
           if(h>maxi)
           {
               maxi=h;
               s=root->val;
           }
           else if(h==maxi)s+=root->val;
           return ;
       }
       solve(root->left,h+1,s,maxi);
        solve(root->right,h+1,s,maxi);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=0,s=0,maxi=0;
        solve(root,h,s,maxi);
        return s;
    }
};
