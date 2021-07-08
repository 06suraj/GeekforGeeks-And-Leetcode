class Solution{
	public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    /* STEPS FOR KOSARAJU' S ALGO
    1. INPUT GRAPH
    2. REVERSE GRAPH
    3.DFS ON INPUT GRAPH
    4.ORDER VECTOR
    5.RUN DFS ON REVERSE GRAPH ON THE BASIS OF REVERSE OF ORDER VECTOR
    */
    void dfs(int src,vector<int>&vis,vector<int>&ord,vector<int>adj[])
    {
        vis[src]=1;
        //cout<<src<<" ";
        for(auto i:adj[src])
        {
            if(vis[i]==0)
            dfs(i,vis,ord,adj);
        }
        ord.push_back(src);
        //cout<<src;
        
    }
    void rdfs(int src,vector<int>&vis,vector<int>adj[])
    {
        vis[src]=1;
        for(auto i:adj[src])
        {
            if(vis[i]==0)
            rdfs(i,vis,adj);
        }
        
    }
    int kosaraju(int V, vector<int> adj[]) {
        //code here
        vector<int>rev[V];
        for(int i=0;i<V;i++)  // reverse graph
        {
            for(auto x:adj[i])
            rev[x].push_back(i);
        }
        vector<int>vis(V,0);   // visited vector
        vector<int>order; // order vector
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            dfs(i,vis,order,adj); // dfs on original graph and store the vertices in order vector
        }
        int ans=0;
        vector<int>vis1(V,0);
        for(int i=V-1;i>=0;i--)
        {
            cout<<order[i]<<" ";
            if(vis1[order[i]]==0)
            {rdfs(order[i],vis1,rev);   // dfs on reverse graph and calculate the components(no. of times dfs runs on reverse graph)
            ans++;}
        }
        return ans;
    }
};
