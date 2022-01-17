class Solution {
public:
    void dfs(int src,vector<pair<int,int>>adj[],vector<int>&value,int maxTime,int currTime,int currVal,int&ans){
        if(currTime>maxTime)return ;
         currVal+=value[src];
        if(src==0)ans=max(ans,currVal);
        int temp=value[src];
        value[src]=0;
        for(auto child:adj[src]){
            dfs(child.first,adj,value,maxTime,currTime+child.second,currVal,ans);
        }
        value[src]=temp;
        
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        // here we will try all possible path for each node such that starting and ending node is 0
        // since a node can have atmost 4 adjacent nodes, so it will have 4 possibilties for traversal and the maximum  number of times it will visit a node is 10(maxtime=100/time for one node to another =10) 
        // so the t.c=O(4^10)=O(2^20);
        int n=values.size();
        vector<pair<int,int>>adj[n];//graph
        
        for(auto i:edges){
            int u=i[0],v=i[1],t=i[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        int ans=0,currTime=0,currVal=0,src=0;
        dfs(src,adj,values,maxTime,currTime,currVal,ans);
        return ans;
    }
};
