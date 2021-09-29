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
    unordered_map<TreeNode*,int>memo;
    
    int solve_recur(TreeNode*root){
        if(root==0)return 0;
        
        int val=0;
        if(root->left)
            val+=solve_recur(root->left->left)+solve_recur(root->left->right);
        if(root->right)val+=solve_recur(root->right->left)+solve_recur(root->right->right);
    
        return(max(solve_recur(root->left)+solve_recur(root->right),root->val+val));
    }
    
    int solve_memo(TreeNode*root){
        if(root==0)return 0;
        
        if(memo.find(root)!=memo.end())return memo[root];
        
        int val=0;
        if(root->left)
            val+=solve_memo(root->left->left)+solve_memo(root->left->right);
        if(root->right)val+=solve_memo(root->right->left)+solve_memo(root->right->right);
    
        return(memo[root]=max(solve_memo(root->left)+solve_memo(root->right),root->val+val));
    }
    
    
    vector<int> solve(TreeNode*root){
        if(root==0)return{0,0};
        
        vector<int>l=solve(root->left);
        vector<int>r=solve(root->right);
       vector<int>curr(2);
        curr[0]=max(l[0],l[1])+max(r[0],r[1]);
        curr[1]=root->val+l[0]+r[0];
        return curr;
    }
    
    int rob(TreeNode* root) {
        // return solve_recur(root); // recursion
        
        memo.clear();
        // return solve_memo(root); //memoisation using hashmap
        
        vector<int>ans= solve(root);  // bottom-up approach by tracking the elements;
        return max(ans[0],ans[1]);
    }
};
