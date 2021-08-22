class Solution {
public:
    int mod=1000000007;
    typedef pair<long long int, long long int> pi;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n];
        int m=roads.size();
        for(int i=0;i<m;i++){
            int u=roads[i][0],v=roads[i][1],w=roads[i][2];
            vector<int>t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        vector<long long int>dist(n,LLONG_MAX);
        priority_queue<pi, vector<pi>, greater<pi> > s;
        set<pair<int,int>>vis;
        s.push(make_pair(0,0));
        int paths[n];
        paths[0]=1;
        dist[0]=0;
        while(!s.empty())
        {
            pair<long long int,long long int>temp=s.top();
            s.pop();
            int u=temp.second;
            long long int d=temp.first;
            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i][0];
              long long   int w=adj[u][i][1];
                if(vis.find({v,u})!=vis.end())continue;
                 if((dist[v])>(dist[u]+w))
                {
                     s.push(make_pair((dist[u]+w),v));
                    dist[v]=(dist[u]+w);
                    paths[v]=(paths[u]%1000000007);
                }else if(dist[v]==(dist[u]+w)){
                     paths[v]=(paths[u]%1000000007+paths[v]%1000000007)%1000000007;
                 }
                 vis.insert({v,u});
                
            }
        
        }
       // cout<<dist[n-1];
        return paths[n-1];
    }
};
