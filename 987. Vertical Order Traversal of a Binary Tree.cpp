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
   static bool cmp(pair<int,int>&a,pair<int,int>&b){
       if(a.first==b.first)return a.second<b.second;
       return a.first<b.first;
   }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,vector<pair<int,int>>>ma;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int h=0;
        while(!q.empty()){
            int si=q.size();
            while(si--){
                auto f=q.front();
                q.pop();
                ma[f.second].push_back({h,f.first->val});
                if(f.first->left){
                    q.push({f.first->left,f.second-1});
                }
                if(f.first->right){
                    q.push({f.first->right,f.second+1});
                }
            }
            h++;
        }
        vector<vector<int>>ans;
        for(auto i:ma){
            vector<pair<int,int>>temp;
            for(auto x:i.second){
                temp.push_back({x.first,x.second});
            }
            sort(temp.begin(),temp.end(),cmp);
            vector<int>temp1;
            for(auto x:temp)temp1.push_back(x.second);
            ans.push_back(temp1);
        }
        return ans;
    }
};
