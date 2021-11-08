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
    int ans=0;
    int toint(string s){
        int num=0;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'0';
            if(x==1)
            num+=pow(2,x*(s.size()-i-1));
        }
        return num;
    }
    void solve(TreeNode*root,string s){
        if(!root)return ;
        if(root->left==0 and root->right==0){
            s+=to_string(root->val);
            ans+=toint(s);
            cout<<toint(s)<<" ";
            return ;
        }
        solve(root->left,s+to_string(root->val));
         solve(root->right,s+to_string(root->val));
    }
    int sumRootToLeaf(TreeNode* root) {
        ans=0;
        solve(root,"");
        return ans;
    }
};
