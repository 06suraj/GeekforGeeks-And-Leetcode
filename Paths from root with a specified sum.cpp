/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution
{
    public:
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(Node*root,int targetsum, int curr_sum){
        if(root==0)return ;
        curr_sum+=root->key;
        temp.push_back(root->key);
        if(curr_sum==targetsum){
            ans.push_back(temp);
            temp.pop_back();
            curr_sum-=root->key;
            return ;
        }
        solve(root->left,targetsum,curr_sum);
        solve(root->right,targetsum,curr_sum);
        curr_sum-=root->key;
        temp.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        ans.clear(),temp.clear();
        solve(root,sum,0);
        return ans;
    }
};
