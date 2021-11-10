class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=0;
        for(int i=0;i<edges.size();i++) n=max(n,max(edges[i][0],edges[i][1]));
        vector<int>adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        vector<int>dis(n+1,0),vis(n+1,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int cnt=1;
        while(!q.empty()){
            int si=q.size();
            while(si--){
                int node=q.front();
                q.pop();
                for(int i:adj[node]){
                    if(vis[i]==0){
                     q.push(i);
                     dis[i]=2*cnt;
                     vis[i]=1;
                    }
                }
            }
            cnt++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int total=dis[i]/patience[i]+(dis[i]%patience[i]?1:0);
            ans=max(ans,(total-1)*patience[i]+dis[i]+1);
        }
        return ans;
        
    }
};
