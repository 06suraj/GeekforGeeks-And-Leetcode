class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(vector<int>edge:times){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX),vis(n+1,0);
        dist[k]=0;
        vis[k]=1;
        set<pair<int,int>>shortest;
        shortest.insert({0,k});
        while(!shortest.empty()){
            pair<int,int>p= *(shortest.begin());
            int u=p.second,d=p.first;
            shortest.erase(shortest.begin());
            for(pair<int,int>adjacent:adj[u]){
                if(vis[adjacent.first]){
                    if(dist[adjacent.first]>dist[u]+adjacent.second){
                       shortest.erase(shortest.find({dist[adjacent.first],adjacent.first}));
                       dist[adjacent.first]=dist[u]+adjacent.second;
                        shortest.insert({dist[adjacent.first],adjacent.first});
                    }
                }else{
                       dist[adjacent.first]=dist[u]+adjacent.second;
                        shortest.insert({dist[adjacent.first],adjacent.first});
                        vis[adjacent.first]=1;
                }
                
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0)return -1;
        }
        return *max_element(dist.begin()+1,dist.end());
    }
};
