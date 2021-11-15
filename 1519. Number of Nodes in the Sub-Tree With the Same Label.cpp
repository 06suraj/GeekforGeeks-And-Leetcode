class Solution {
public:
    vector<int>dfs(vector<int>adj[],int src,int par,vector<int>&ans,string& label){
        vector<int>counter(26,0);
        for(int i:adj[src]){
            if(i!=par){
                vector<int>temp=dfs(adj,i,src,ans,label);
                for(int i1=0;i1<26;i1++)counter[i1]+=temp[i1];
            }
        }
        counter[label[src]-'a']++;
        ans[src]=counter[label[src]-'a'];
        return counter;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>adj[n],ans(n);
        for(vector<int>edg:edges){
            int u=edg[0],v=edg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,0,-1,ans,labels);
        return ans;
    }
};
