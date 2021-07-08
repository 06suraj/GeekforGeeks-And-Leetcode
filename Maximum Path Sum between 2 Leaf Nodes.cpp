class Solution {
public:
   int ans,sum=0;
    int solve(Node*root){
        if(root==0)return 0;
        if(root->left==0 and root->right==0)return root->data;
        int l=solve(root->left);
        int r=solve(root->right);
       // cout<<l<<" "<<r<<" ";
        int temp=max(l,r)+root->data;
      // cout<<temp<<endl;
      if(root->right and root->left)
        {ans=max(ans,l+r+root->data);
        return temp;}
      if(root->left==0)return(r+root->data);
      else return l+root->data;
     
    }
    void s(Node*root){
        if(!root)return ;
        
        s(root->left);
        s(root->right);
        sum+=root->data;
    }
    int maxPathSum(Node* root)
    {
        // code here
         ans=INT_MIN,sum=0;
        solve(root);
        
        if(ans==INT_MIN){
         s(root);  
         ans=sum;
        
        }
        return ans;
    }
};
