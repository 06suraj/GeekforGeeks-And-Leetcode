class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>&vis,int src){
        vis[src]=1;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[src][j]==1 and vis[j]==0)
                dfs(isConnected,vis,j);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),cnt=0;
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i]==0 and isConnected[i][j]==1){
                    cnt++;
                    dfs(isConnected,vis,i);
                }
            }
        }
        return cnt;
    }
};
