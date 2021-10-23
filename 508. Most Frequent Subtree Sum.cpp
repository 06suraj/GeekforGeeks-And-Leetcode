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
    unordered_map<int,int>ma;
    int solve(TreeNode*root){
        if(!root)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        ma[l+r+root->val]++;
        return l+r+root->val;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
       ma.clear();
        solve(root);
        int maxi=INT_MIN;
        for(auto i:ma)maxi=max(maxi,i.second);
        vector<int>ans;
        for(auto i:ma){
            if(i.second==maxi)ans.push_back(i.first);
        }
        return ans;
    }
};
