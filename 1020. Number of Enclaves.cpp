class Solution {
public:
    int dirx[4]={0,0,1,-1};
    int diry[4]={1,-1,0,0};
    void count(vector<vector<int>>&grid,vector<vector<int>>&vis,int x,int y,int& cnt){
        vis[x][y]=1;
        cnt++;
        for(int i=0;i<4;i++){
            int newx=x+dirx[i],newy=y+diry[i];
            if(newx<0 or newy<0 or newx>=grid.size() or newy>=grid[0].size() or grid[newx][newy]==0 or vis[newx][newy]==1){
                continue;
            }
            count(grid,vis,newx,newy,cnt);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i][0] and grid[i][0]==1)count(grid,vis,i,0,cnt);
            if(!vis[i][m-1] and grid[i][m-1]==1)count(grid,vis,i,m-1,cnt);
        }
        for(int j=0;j<m;j++){
            if(!vis[0][j] and grid[0][j]==1)count(grid,vis,0,j,cnt);
            if(!vis[n-1][j] and grid[n-1][j]==1)count(grid,vis,n-1,j,cnt);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    cnt=0;
                    count(grid,vis,i,j,cnt);
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};
