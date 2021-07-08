
class Solution{
    public:
     void dfs(int src,vector<vector<char>>&G,vector<int>&vis,string&ans) // TOPO SORT USING DFS
    {
        vis[src]=1;
        for(auto i:G[src])
        {
            if(vis[i]==0)
            dfs(i,G,vis,ans);
        }
        ans=(char)src+ans;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<char>>graph(124);  // CREATE A GRAPH 
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            for(int j=0;j<min(s1.length(),s2.length());j++)
            {
                if(s1[j]!=s2[j])
                {graph[s1[j]].push_back(s2[j]);
                break;}
            }
        }
        vector<int>vis(124,0);
        string ans="";
        for(int i=97;i<97+K;i++)
        {
            if(vis[i]==0)
            dfs(i,graph,vis,ans);
        }
        return ans;
    }
};
