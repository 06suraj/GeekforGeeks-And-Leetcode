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
    string dfs1(TreeNode*subroot){
        if(!subroot)return "";
        string x=dfs1(subroot->left);
        string y=dfs1(subroot->right);
        string s=x+'#'+y+'#'+to_string(subroot->val);
        return s;
    }
    int ans=0;
    string dfs2(TreeNode*root,string to_check){
        if(!root)return"";
        string x=dfs2(root->left,to_check);
        string y=dfs2(root->right,to_check);
         string s=x+'#'+y+'#'+to_string(root->val);
        if(s==to_check)ans=1;
        return s;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ans=0;
        string s="";
        s=dfs1(subRoot);
        dfs2(root,s);
        return ans;
        
    }
};
