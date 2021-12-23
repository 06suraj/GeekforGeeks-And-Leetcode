/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node*node,map<Node*,Node*>&vis){
        if(!node)return 0;
        Node *CopyNode=new Node(node->val);
        vis[node]=CopyNode;
        for(auto child:node->neighbors){
            Node*childCopy;
            if(vis.find(child)==vis.end())
            childCopy=dfs(child,vis);
            else childCopy=vis[child];
            CopyNode->neighbors.push_back(childCopy);
        }
        return CopyNode;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>vis;
        Node* head=dfs(node,vis);
        return head;
        
       
    }
};
