class Solution {
public:
    typedef vector<int>pi;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>adj[n];
        for(int i=0;i<flights.size();i++){
            
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
      priority_queue<pi, vector<pi>, greater<pi> > pq;
     vector<int>edge_count(n,INT_MAX);
     edge_count[src]=0;;
      pq.push({0,src,0});
      while(!pq.empty()){
         vector<int>temp=pq.top();
          pq.pop();
          int cost=temp[0],u=temp[1],step=temp[2];
          
          if(edge_count[u]<step)continue;   // this will check if this node already uses less number of edges , so we will not consider it again
          edge_count[u]=step;
          
          if(u==dst)return cost;
          
          if(step==k+1)continue;
          
          for(int i=0;i<adj[u].size();i++){
              int v=adj[u][i][0];
              int d=adj[u][i][1];
               pq.push({cost+d,v,step+1});
              }
             
          }
        return -1 ;
      }
        // cout<<"dbg";
        // return -1 ;
    
};
