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
    TreeNode*build(vector<int>&post,vector<int>&in,int lb,int ub)
    {
        if(lb>ub)return NULL;
        TreeNode*temp=new TreeNode(post[ind++]);
        if(lb==ub)return temp;
        int mid=m[temp->val];
        temp->right=build(post,in,mid+1,ub);
        temp->left=build(post,in,lb,mid-1);
        return temp;


    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {
    ind=0;
    reverse(post.begin(),post.end());
    m.clear();
    for(int i=0;i<inorder.size();i++)m[inorder[i]]=i;
    TreeNode*temp=build(post,inorder,0,post.size()-1);
    return temp;
}
};
