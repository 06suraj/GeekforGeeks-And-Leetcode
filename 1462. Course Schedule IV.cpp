class Solution {
public:
    void dfs(int src,vector<int>adj[],vector<int>&order,vector<int>&vis){
        vis[src]=1;
        for(int child:adj[src]){
            if(!vis[child])dfs(child,adj,order,vis);
        }
         order.insert(order.begin(), src);
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
      vector<int>adj[numCourses];
      for(vector<int>edge:prerequisites){
          int u=edge[0],v=edge[1];
          adj[u].push_back(v);
      }
      vector<int>vis(numCourses,0),order;
      vector<bool>ans;
      set<pair<int,int>>s;
      for(int i=0;i<numCourses;i++)
      {
          for(int j=0;j<numCourses;j++)vis[j]=0;
          order.clear();
          if(!vis[i])dfs(i,adj,order,vis);
          for(int j:order){
              s.insert({i,j});
          }
          
      }
     
    for(vector<int>query:queries){
        if(s.find({query[0],query[1]})!=s.end())ans.push_back(1);
        else ans.push_back(0);
      }
        return ans;
    }
};
