class Solution {
public:
    
    int dfs(int src,int n,vector<vector<int>> adj[],vector<int>&dist,vector<int>&memo){
        if(memo[src]!=-1) return memo[src];
        if(src==n)return 1;
        int ans=0;
        for(int i=0;i<adj[src].size();i++){
            int v=adj[src][i][0];
            if(dist[v]<dist[src])ans=(ans+dfs(v,n,adj,dist,memo))%1000000007;
        }
        return memo[src]=ans%1000000007;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edge) {
         vector<vector<int>> adj[n+1];
         for(vector<int>i:edge){
            int u=i[0],v=i[1],w=i[2];
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>>s;
        s.insert(make_pair(0,n));
        dist[n]=0;
        while(!s.empty())
        {
            pair<int,int>temp=*s.begin();
            s.erase(s.begin());
            int u=temp.second;
            int d=temp.first;
            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i][0];
                int w=adj[u][i][1];
                 if(dist[v]>dist[u]+w)
                {
                     auto f=s.find(make_pair(dist[v],v));
                    if(f!=s.end())
                    s.erase(f);
                    s.insert(make_pair(dist[u]+w,v));
                    dist[v]=dist[u]+w;
                }
            }
        
        }
        vector<int>memo(n+1,-1);
        return(dfs(1,n,adj,dist,memo));
        
    }
};
