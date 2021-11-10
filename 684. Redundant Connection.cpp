class Solution {
public:
    int parent[1001],rank[1001];
    
    int find(int node){
        if(parent[node]==node)return node;
       return parent[node]=find(parent[node]);
    }
    
    void unio(int u,int v){
        int par_u=find(u),par_v=find(v);
        if(rank[par_u]>rank[par_v])parent[par_v]=par_u;
        else if(rank[par_u]<rank[par_v])parent[par_u]=par_v;
        else{
            parent[par_v]=par_u;
            rank[par_u]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       for(int i=1;i<=edges.size();i++)parent[i]=i;
        memset(rank,0,sizeof(rank));
        
        vector<int>ans(2);
        for(vector<int>i:edges){
            int u=i[0],v=i[1];
            if(find(u)==find(v))ans[0]=u,ans[1]=v;
            else unio(u,v);
        }
        return ans;
    }
};
