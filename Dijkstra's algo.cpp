class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    /*IMPLEMENTED USING SET*/
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        vector<int>dist(V,INT_MAX);
        set<pair<int,int>>s;
        s.insert(make_pair(0,S));
        dist[S]=0;
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
                    if(f!=s.end() and dist[v]!=INT_MAX)
                    s.erase(f);
                    s.insert(make_pair(dist[u]+w,v));
                    dist[v]=dist[u]+w;
                }
            }
        
        }
        return dist;
    }
};
