class Solution {
public:
    bool check(int src,int par,int col,vector<vector<int>>& graph,vector<int>&vis){
        vis[src]=col;
        for(int child:graph[src]){
            if(!vis[child] and check(child,src,3-col,graph,vis)==0)return 0;
            else if(child!=par and vis[child]==col)return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
      vector<int>vis(graph.size(),0);
        for(int i=0;i<graph.size();++i){
            if(vis[i]==0 && check(i,-1,1,graph,vis)==false){ 
                return false;
            }
        }
        return true;
    }
};
