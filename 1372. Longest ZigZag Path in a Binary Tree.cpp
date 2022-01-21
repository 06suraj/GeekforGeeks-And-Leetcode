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
    void solve(TreeNode*root,int& ans,int left,int step){
        if(!root)return ;
        ans=max(ans,step);
        if(left){
            solve(root->right,ans,!left,step+1);
            solve(root->left,ans,left,1);
        }else{
            solve(root->left,ans,!left,step+1);
            solve(root->right,ans,left,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans=0,step=0,left=0;
        solve(root,ans,left,step);
        step=0;
        solve(root,ans,!left,step);
        return ans;
        
    }
};
