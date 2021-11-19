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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int si=q.size(),prev;
            if(level%2)prev=INT_MAX;
            else prev=-1;
            while(si--){
                TreeNode*top=q.front();
                q.pop();
                if(level%2 and top->val%2)return 0;
                else if(level%2==0 and top->val%2==0)return 0;
                
                if(level%2 and top->val>=prev)return 0;
                else if(level%2==0 and top->val<=prev)return 0;
                
                prev=top->val;
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            level++;
        }
        return 1;
    }
};
