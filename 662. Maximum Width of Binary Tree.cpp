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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<unsigned long long,TreeNode*>>q;  
        q.push({0,root});
        unsigned long long ans=1;
        while(!q.empty()){
            int si=q.size();
           unsigned long long int left=q.front().first,right=left;
            while(si--){
                TreeNode*temp=q.front().second;
                right=q.front().first;
                q.pop();
                if(temp->left)
                    q.push({2*right+1,temp->left});
                if(temp->right)
                    q.push({2*right+2,temp->right});
                
            }
            ans=max(ans,right-left+1);
        }
        return(int)ans;
        
    }
};
