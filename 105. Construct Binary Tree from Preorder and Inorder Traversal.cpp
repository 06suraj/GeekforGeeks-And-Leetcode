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
     map<int,int>m;
    int ind=0;
    TreeNode*build(vector<int>&pre,vector<int>&in,int lb,int ub)
    {
        if(lb>ub)return NULL;
        TreeNode*temp=new TreeNode(pre[ind++]);
        if(lb==ub)return temp;
        int mid=m[temp->val];
        temp->left=build(pre,in,lb,mid-1);
        temp->right=build(pre,in,mid+1,ub);
        return temp;


    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& inorder) {
    ind=0;
    m.clear();
    for(int i=0;i<inorder.size();i++)m[inorder[i]]=i;
    TreeNode*temp=build(pre,inorder,0,pre.size()-1);
    return temp;
}
};
