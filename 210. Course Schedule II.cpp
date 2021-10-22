class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>deg(n,0),vis(n,0),ans;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            deg[i[1]]++;
        }
       
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==0)q.push(i),vis[i]=1;
        }
        
        while(!q.empty()){
           int curr=q.front();
            q.pop();
           ans.push_back(curr);
           for(int i:adj[curr]){
               if(!vis[i]){
                   deg[i]--;
                   if(deg[i]==0)q.push(i),vis[i]=1;
               }
           }
            
        }
        if(ans.size()!=n)return {};
        else{
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};
