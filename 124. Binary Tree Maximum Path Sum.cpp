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
    int ans;
    int solve(TreeNode*root){
        if(root==0)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        //cout<<l<<" "<<r<<" ";
        int temp=max(max(l,r)+root->val,root->val);
        ans=max(ans,max(temp,l+r+root->val));
        return temp;
     
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        solve(root);
        return ans;
    }
};
