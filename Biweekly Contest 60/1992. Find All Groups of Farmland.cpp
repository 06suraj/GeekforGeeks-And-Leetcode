class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& vis,int r1,int c1,vector<vector<int>>& ans,int n,int m){
        queue<pair<int,int>>q;
        q.push({r1,c1});
        vector<int>temp;
        temp.push_back(r1);
        temp.push_back(c1);
        vis[r1][c1]=1;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i+1<n and j<m and j>=0 and vis[i+1][j]==0 and mat[i+1][j]==1)
            {
                q.push({i+1,j});
                vis[i+1][j]=1;
            }
            if(i<n and i>=0 and j+1<m and j>=0 and vis[i][j+1]==0 and mat[i][j+1]==1)
            {
                q.push({i,j+1});
                vis[i][j+1]=1;
            }
            if(i-1>=0 and i<n and j<m and j>=0 and vis[i-1][j]==0 and mat[i-1][j]==1)
            {
                q.push({i-1,j});
                vis[i-1][j]=1;
            }
            if(i<n and i>=0 and j-1>=0 and j<m and vis[i][j-1]==0 and mat[i][j-1]==1)
            {
                q.push({i,j-1});
                vis[i][j-1]=1;
                
            }
            if(q.empty())
            {temp.push_back(i);
                  temp.push_back(j);}
            
            
        }
        ans.push_back(temp);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int n=land.size(),m=land[0].size();
        vector<vector<int>>vis;
        vector<int>temp(m,0);
        for(int i=0;i<n;i++)vis.push_back(temp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 and land[i][j]==1){
                    bfs(land,vis,i,j,ans,n,m);
                }
            }
        }
        return ans;
        
    }
};
