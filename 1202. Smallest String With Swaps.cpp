class Solution {
public:
    void dfs(int src,vector<int>adj[],vector<int>&vis,vector<int>&pos,string&temp,string&s){
        vis[src]=1;
        pos.push_back(src);
        temp+=s[src];
        for(int i:adj[src]){
            if(!vis[i])dfs(i,adj,vis,pos,temp,s);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
       vector<char>ans(n);
        string x="";
        vector<int>adj[n],vis(n,0),pos;
        for(vector<int>edge:pairs){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pos,x,s);
                sort(x.begin(),x.end());
                sort(pos.begin(),pos.end());
                for(int i=0;i<pos.size();i++){
                    ans[pos[i]]=x[i];
                }
                x.clear(),pos.clear();
            }
        }
        string temp="";
        for(char i:ans)temp+=i;
        return temp;
        
        
    }
};
