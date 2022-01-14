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
    vector<int> solve(TreeNode*root,int& ans){
        if(!root)return {INT_MAX,INT_MIN};
        if(!root->left and !root->right)return {root->val,root->val};
        if(!root->left){
            vector<int>r=solve(root->right,ans);
            int maxi=r[0];
            int mini=r[1];
            ans=max(ans,abs(root->val-maxi));
            ans=max(ans,abs(root->val-mini));
            ans=max(ans,0);
            return {max(maxi,root->val),min(mini,root->val)};
        }
        if(!root->right){
            vector<int>l=solve(root->left,ans);
            int maxi=l[0];
            int mini=l[1];
            ans=max(ans,abs(root->val-maxi));
            ans=max(ans,abs(root->val-mini));
            ans=max(ans,0);
            return {max(maxi,root->val),min(mini,root->val)};
        }
        vector<int>l=solve(root->left,ans);
        vector<int>r=solve(root->right,ans);
        int maxi=max(l[0],r[0]);
        int mini=min(l[1],r[1]);
        ans=max(ans,abs(root->val-mini));
        ans=max(ans,abs(root->val-maxi));
        ans=max(ans,0);
        return {max(maxi,root->val),min(root->val,mini)};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
