class Solution{
	public:
	/* the graph must be directed acyclic graph and we just print the vertices in ascending order of indegree*/
   void dfs(int src,vector<int>adj[],vector<int>&vis,vector<int>&ans) // dfs code for topo sort
   {
       vis[src]=1;
       for(auto i:adj[src])
       {
           if(vis[i]==0)
           dfs(i,adj,vis,ans);
       }
       ans.insert(ans.begin(), src);  // stack can also be used
   }
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int> in(V,0);   // to store the indegree
	    vector<int> ans;
	    vector<int>vis(V,0);
	    /* for BFS IMPLEMENTATIOON WE REQUIRED INDEGREE */
	   /* queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        for(auto x:adj[i])
	        in[x]++;         // calcuate the indegree of all vertices
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(in[i]==0)      
	        q.push(i);
	    }
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);   // store the result
	        for(auto x:adj[temp]){
	            in[x]--;           // update the indegree of adjacent vertices 
	            if(in[x]==0)
	            q.push(x);
	        }
	    }*/
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            dfs(i,adj,vis,ans);
	        }
	    }
	    
	    return ans;
	}
};
