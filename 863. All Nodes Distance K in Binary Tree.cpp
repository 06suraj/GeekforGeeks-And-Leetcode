/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       TreeNode*dest;
       unordered_map<TreeNode*,TreeNode*>par;  // parent of each node
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
           TreeNode*temp=q.front();
           q.pop();
           if(temp->left){
               par[temp->left]=temp;
               q.push(temp->left);
           }
           if(temp->right){
               par[temp->right]=temp;
               q.push(temp->right);
           }
       }
       set<TreeNode*>vis;
       vis.insert(target);
       q.push(target);
        
       // bfs in all posible direction(i.e left, right and parent)
        
       while(!q.empty() and k){
           k--;
           int si=q.size();
           while(si--){
              TreeNode*temp=q.front();
               q.pop();
               if(temp->left and vis.find(temp->left)==vis.end())
               {
                   q.push(temp->left);
                   vis.insert(temp->left);
                }
               if(temp->right and vis.find(temp->right)==vis.end())
               {
                   q.push(temp->right);
                  vis.insert(temp->right);
                }
               if(par.find(temp)!=par.end() and vis.find(par[temp])==vis.end()){
                   q.push(par[temp]);
                   vis.insert(par[temp]);
               }
               
           }
       }
       vector<int>ans;
       while(!q.empty()){
           ans.push_back(q.front()->val);
           q.pop();
       }
       return ans;
       
       
    }
};
