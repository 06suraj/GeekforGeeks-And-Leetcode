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
    int ans=-1001;
    vector<int>solve(TreeNode*root){
        if(root==0)
            return {-1001,-1001};
        vector<int>l=solve(root->left);
        vector<int>r=solve(root->right);
        if(l[1]==root->val and r[1]==root->val){
            ans=max(ans,l[0]+r[0]+1);
            return{max(l[0],r[0])+1,root->val};
        }else if(l[1]==root->val){
            ans=max(ans,l[0]+1);
            return {l[0]+1,l[1]};
        }else if(r[1]==root->val){
           ans=max(ans,r[0]+1);
            return {r[0]+1,r[1]};
        }
        else {
            ans=max(ans,1);
            return{1,root->val};
        }
    }
    
    int longestUnivaluePath(TreeNode* root) {
         solve(root);
        if(ans==-1001)return 0;
        return ans-1;
    }
};
