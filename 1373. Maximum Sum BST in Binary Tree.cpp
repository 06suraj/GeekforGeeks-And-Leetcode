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
  /* HERE WE CAN FIRST USE BRUTE FORCE METHOD IN WHICH FOR EVRYNODE WE WILL CALCUALTE THE LARGEST SUM OF THE SUBTREE IT HAS AND WHICH IS ALSO A BST AND IT WILL TAKE O(N^2) IN WORST CASE , SO HERE WE WILL A POST ORDER TRAVERSAL TRAVERSING FROM SUBTREE TO PARENT INSTEAD OF PARENT TO SUBTREE AND  KEEP THE TRACK OF INFORMATION OF SUM , BST(WHETHER THE CURRENT TREE IS A BST OR NOT ) AND MAXIMUM AND MINIMUM OF THAT SUBTREE AND FINALLY A ANSWER VARIABLE WHICH WILL GIVE ME FINAL ANSWER  AND T.C FOR THIS IS O(N) SINCE WE ARE TRAVERSING EACH AND EVERY NODE ONLY ONCE*/
   int ans=0;
   vector<int>solve(TreeNode*root){
       
       if(!root)return {1,INT_MAX,INT_MIN,0}; // if there is no node then simply return ideal case
       
       if(!root->left and !root->right)   /// if it is a leaf node then simply return node value to its  ancestors 
       {
           ans=max(ans,root->val);
           return {1,root->val,root->val,root->val};
       }
       
       vector<int>left=solve(root->left);  // this vector will give me information about left subtree 
       vector<int>right=solve(root->right); // // this vector will give me information about right subtree
       if(left[0] and right[0]){
           if(left[2]<root->val and right[1]>root->val){   // to check whether the current node will form a bst based on the information of left and right subtree
               int mini=left[1],maxi=right[2];
               if(mini==INT_MAX)mini=root->val;
               if(maxi==INT_MIN)maxi=root->val;
               int sum=left[3]+right[3]+root->val;
               ans=max(ans,sum);
               return {1,mini,maxi,sum};
            }
       }
       return {0,0,0,0};  // this is just a formality(or just to return something) because it the current node will not form  a bst then definitely the ancestors of this node will also not  form a bst
       
       
   }
    int maxSumBST(TreeNode* root) {
        ans=0;
        vector<int>bstInfo=solve(root);
        return ans;
    }
};
