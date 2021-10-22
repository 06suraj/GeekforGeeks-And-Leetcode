class Solution {
public:
    
    void dfs(vector<int>adj[],int node,int par,vector<int>&ans,vector<int>&temp,int height,int& maxi){
        temp.push_back(node);
        height++;
        if(height>maxi){
            maxi=height;
            ans=temp;
        }
        for(int i:adj[node]){
            if(i!=par){
                dfs(adj,i,node,ans,temp,height,maxi);
            }
        }
        temp.pop_back();
        
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>deg(n,0),vis(n,0),ans;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            deg[i[0]]++,deg[i[1]]++;
        }
        
        //1. USING BFS TOPOSORT , i.e if we consider this problem as 1d , then the node which has minimum distance from extremum are mid nodes , so in 1d we will consider two pointer , one from first and one last , so the node or indices where two pointer meet or at a distance of 1 are the required node or indices , similarly here we dont gonna take  pointer rather , we will consider from leave nodes ,and simultaneously trim them unitl we will get one or two nodes at the end , and this implementation is quite a bit similar to that of kahn's algo 
        queue<int>q;
        int node_count=n;
        for(int i=0;i<n;i++){
            if(deg[i]==1)q.push(i),vis[i]=1;
        }
        
        while(node_count>2){
           int siz=q.size();
            node_count=node_count-siz;
            while(siz--){
                int curr=q.front();
                q.pop();
                for(auto i:adj[curr]){
                    if(!vis[i])
                    {
                        deg[i]--;
                        if(deg[i]==1)q.push(i),vis[i]=1;
                    }
                }
            }
        }
        if(q.empty())return {0};
      while(!q.empty()){
          ans.push_back(q.front());
          q.pop();
      }
        
        
      //2. USING DIAMETER OF TREE(DFS) , i.e we will the trace the longest path of the tree by using DFS two times, although there can be more than  one path , but surely there will atleat one node which is common to all paths , ans that node or two node depending upon the size of the path , will be our answer according the intution given above
      ans.clear();
      vector<int>temp;
       int maxi=INT_MIN;
      dfs(adj,0,-1,ans,temp,0,maxi);
      int curr=ans[ans.size()-1]; 
      ans.clear(),temp.clear();
      maxi=INT_MIN;
      dfs(adj,curr,-1,ans,temp,0,maxi);
      if(ans.size()%2)return {ans[ans.size()/2]};
      else return {ans[ans.size()/2],ans[ans.size()/2-1]};
    }
};
