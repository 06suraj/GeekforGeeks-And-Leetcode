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
    TreeNode*findHead(TreeNode*root,int low,int high){
        if(!root)return 0;
        if(root->val>=low and root->val<=high)return root;
        if(root->val<low)return findHead(root->right,low,high);
        else return findHead(root->left,low,high);
    }
    
    TreeNode*trim(TreeNode*root,int low,int high){
        if(!root)return 0;
        if(root->val<low)return trim(root->right,low,high);
        else if(root->val>high)return trim(root->left,low,high);
        else{
            TreeNode*left=trim(root->left,low,high);
            TreeNode*right=trim(root->right,low,high);
            root->left=left,root->right=right;
            return root;
        }
        
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode*head=findHead(root,low,high);
        trim(root,low,high);
        return root;
    }
};
