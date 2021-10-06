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
    void solve(TreeNode* root, vector<string>&s,string temp){
        if(root->left==0 and root->right==0){
            s.push_back(temp+to_string(root->val));
            return ;
        }
    
        if(root->left)
        solve(root->left,s,temp+to_string(root->val));
        if(root->right)
        solve(root->right,s,temp+to_string(root->val));
        
    }
    int sumNumbers(TreeNode* root) {
        vector<string>s;
        solve(root,s,"");
        int ans=0;
        for(string s1:s){
            ans+=stoi(s1);
        }
        return ans;
    }
};
