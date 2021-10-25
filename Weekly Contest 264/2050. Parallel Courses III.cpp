class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n];
        vector<int>indeg(n,0);
        for(auto i:relations){
            adj[i[0]-1].push_back(i[1]-1);
            indeg[i[1]-1]++;
        }
       vector<int>dist(n,0);
       queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i),dist[i]=time[i];
        }
       
        int ans=0;
        while(!q.empty()){
            int node=q.front(),cur_time=dist[node];
            q.pop();
            ans=max(ans,dist[node]);
            for(int i:adj[node]){
                indeg[i]--;
                dist[i]=max(time[i]+cur_time,dist[i]);
                if(indeg[i]==0)q.push(i);
            }
        
        }
        return ans;
    }
};
