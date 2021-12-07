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
    TreeNode*lca(TreeNode* root, int startValue, int destValue){
        if(!root)return 0;
        if(root->val==startValue or root->val==destValue)return root;
        TreeNode*left=lca(root->left,startValue,destValue);
        TreeNode*right=lca(root->right,startValue,destValue);
        if(left and right) // this will be lca 
            return root;
        else if(left)return left;
        else if(right)return right;
        else return 0;
    }
    bool getPath(TreeNode*lc,int node,string&s){
        if(!lc)return 0;
        if(lc->val==node)return 1;
        s.push_back('L');
        int l=getPath(lc->left,node,s);
        if(l)return 1;
        s.pop_back();
        s.push_back('R');
        int r=getPath(lc->right,node,s);
        if(r)return 1;
        s.pop_back();
        return 0;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // here we just find the lca of noth the node and then find the corresponding path and concatenate both the path , so total time complexity is o(N) and total traversal of tree is atmost 3(1 for lca nd 2 for direction) we can  also avoid to find the lca and just find both the path and remove the common prefix, in that case total traversal would be 2 
        // TreeNode*lc=lca(root,startValue,destValue);
        string pathL2s="",pathL2d="",ans="";
        getPath(root,startValue,pathL2s);
        getPath(root,destValue,pathL2d);
        // cout<<pathL2s<<" "<<pathL2d<<endl;
        int i=0;
        while(i<pathL2s.size() and i<pathL2d.size() and pathL2s[i]==pathL2d[i])i++; // this wil simply remove the prefix path untill therby avoid to find the lca
        for(int j=i;j<pathL2s.size();j++)ans+='U';
        while(i<pathL2d.size())ans+=pathL2d[i++];
        return ans;
        
        
    }
};
