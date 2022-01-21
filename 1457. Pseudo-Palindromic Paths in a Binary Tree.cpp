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
    unordered_map<int,int>path;
    bool checkPal(){
        int odd=0;
        for(auto i:path){
            if((i.second)%2)odd++;
        }
        if(odd>1)return 0;
        return 1;
    }
    void solve(TreeNode*root,int& ans){
        if(!root)return ;
        if(!root->left and !root->right){
            path[root->val]++;
            if(checkPal())ans++;
            path[root->val]--;
            return ;
        }
        path[root->val]++;
        solve(root->left,ans);
        solve(root->right,ans);
       path[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       int ans=0;
       path.clear();
       solve(root,ans);
        return ans;
    }
};
