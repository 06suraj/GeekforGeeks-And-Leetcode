/*
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        //code here
        queue<Node*>q;
        q.push(root);
        Node*temp;
        int flag=0;
        while(!(q.empty())){
            int si=q.size();
            if(flag)break;
            while(si--){
            temp=q.front();
            q.pop();
            if(temp->left== node_to_find or temp->right== node_to_find){
             flag=1;
            
            }
            else {
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);}
        }
    }
        if(flag==0)return{-1};
        else{
           
            int si=q.size();
            vector<int>ans;
            while(si--){
                temp=q.front();
                q.pop();
                ans.push_back(temp->data);
            }
            if(ans.size()==0)return {-1};
            return ans;
            
        }
    }
    
};
