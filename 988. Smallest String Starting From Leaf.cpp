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
    //HERE WE CANT WE USE POSTORDER (BOTTOM UP OR DIVIDE AND CONQUER) BECAUSE WE ARE ASSUMING THAT EACH LOCAL OPTIMUM STATE WILL LEADS US TO GLOBAL OPTIMUM (GREEDY ALGO.) WHICH WILL NOT WORK FOR HERE e.g.  https://leetcode.com/problems/smallest-string-starting-from-leaf/discuss/244205/Divide-and-conquer-technique-doesn't-work-for-this-problem  SO HERE WE WILL USE BRUTE FORCE OR PRE ORDER
    
    
    void solve(TreeNode*root,string s,string&ans){
        if(!root)return;
        if(!root->left and !root->right){
            s+=(root->val+'a');
            reverse(s.begin(),s.end());
            if(ans=="" or s<ans)ans=s;
        }
        s+=(root->val+'a');
        solve(root->left,s,ans);
        solve(root->right,s,ans);
        
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
       solve(root,"",ans);
        return ans;
    }
};
