class Solution {
public:
    void dfs(int src,vector<int>adj[],vector<int>&vis,vector<int>&pos){
        vis[src]=1;
        pos.push_back(src);
        for(int i:adj[src]){
            if(!vis[i])dfs(i,adj,vis,pos);
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size(),ans=0;
        vector<int>adj[n],vis(n,0),pos;
        for(vector<int>edge:allowedSwaps){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
               dfs(i,adj,vis,pos);
               unordered_map<int,int>a;
                for(int i1:pos){
                    a[source[i1]]++;
                }
                for(int i1:pos){
                    if(a[target[i1]]<1)ans++;
                    else a[target[i1]]--;
                   
                }
                pos.clear();
            }
        }
        return ans;
    }
};
