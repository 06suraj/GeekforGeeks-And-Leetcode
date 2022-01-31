class Solution {
public:
    void preprocessing(int src,int par,vector<int>adj[],vector<long long int>&subTreeAns,vector<long long int>&cntNode){
        cntNode[src]=1;
        subTreeAns[src]=0;
        for(int child:adj[src]){
            if(child!=par){
                preprocessing(child,src,adj,subTreeAns,cntNode);
                cntNode[src]+=cntNode[child];
                subTreeAns[src]+=subTreeAns[child]+cntNode[child];
            }
        }
    }
    
    void findAns(int src,int par,vector<int>adj[],vector<int>&ans,vector<long long int>&cntNode,int totalNodes){
        if(par!=-1)
        ans[src]=ans[par]+totalNodes-2*cntNode[src];
        for(int child:adj[src]){
            if(child!=par)findAns(child,src,adj,ans,cntNode,totalNodes);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(vector<int>edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long long int>subTreeAns(n,0),cntNode(n,0);
        vector<int>ans(n,0);
        preprocessing(0,-1,adj,subTreeAns,cntNode);
        ans[0]=subTreeAns[0];
        findAns(0,-1,adj,ans,cntNode,n);
        for(int i:subTreeAns)cout<<i<<" ";
        return ans;
        
    }
};
