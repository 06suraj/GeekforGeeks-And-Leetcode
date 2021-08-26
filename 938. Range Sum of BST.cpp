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
    int rangeSumBST(TreeNode* root, int l, int h) {
    int count=0;
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty())
  {
      TreeNode*temp=q.front();
      if(temp->val>=l&&temp->val<=h)count+=temp->val;
      q.pop();
      if(temp->left)q.push(temp->left);
      if(temp->right)q.push(temp->right);
  }
  return count;
        
    }
};
