class Solution {
public:
    bool possible(int src,int par,vector<int>adj[],vector<int>&vis,int col){
        vis[src]=col;
        for(int child:adj[src]){
            if(!vis[child] and !possible(child,src,adj,vis,3-col))return false;
            else if(child!=par and vis[child]==col)return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(vector<int>edge:dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i] and !possible(i,-1,adj,vis,1))return false;
        }
        return true;
    }
};
