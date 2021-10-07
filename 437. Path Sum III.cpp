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
    void checksum(TreeNode*curr,int val,int targetsum,int &cnt){
        if(curr==0) return ;
        if(curr->val+val==targetsum)cnt++;
        checksum(curr->left,curr->val+val,targetsum,cnt);
        checksum(curr->right,curr->val+val,targetsum,cnt);
       
    }
    
    void solve(TreeNode*root,int targetsum,int&ans){
        if(!root)return ;
        int cnt=0;
        checksum(root,0,targetsum,cnt);
        ans+=cnt;
        solve(root->left,targetsum,ans);
        solve(root->right,targetsum,ans);
       
    }
    
    void solve_prefix(TreeNode*root,unordered_map<int,int>&ma,int& prefixsum,int&k,int&ans){
        if(!root)return ;
        
        prefixsum+=root->val;
        if(ma.find(prefixsum-k)!=ma.end())ans+=ma[prefixsum-k];
        ma[prefixsum]++;
        solve_prefix(root->left,ma,prefixsum,k,ans);
        solve_prefix(root->right,ma,prefixsum,k,ans);
        ma[prefixsum]--;
        prefixsum-=root->val;
        
    }
    
    int pathSum(TreeNode* root, int targetsum) {
      int ans=0;
        // solve(root,targetsum,ans);  // O(N^2)  BRUTE FORCE 
        
        // USING HASHMAP AND PREFIXSUM O(N^2)->O(N);
        unordered_map<int,int>ma;
        ma[0]=1;
        int prefix=0;
        solve_prefix(root,ma,prefix,targetsum,ans);
        return ans;
    }
};
