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
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(TreeNode*root,int targetsum, int curr_sum){
        if(!root)return ;
        if(root->left==0 and root->right==0){
            if(curr_sum+root->val==targetsum){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return ;
        }
        curr_sum+=root->val;
        temp.push_back(root->val);
        solve(root->left,targetsum,curr_sum);
        solve(root->right,targetsum,curr_sum);
        curr_sum-=root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      ans.clear(),temp.clear();
      solve(root,targetSum,0);
      return ans;
    }
};
