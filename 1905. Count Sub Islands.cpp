class Solution {
public:
    int dirx[4]={0,1,-1,0};
    int diry[4]={1,0,0,-1};
    bool isSafe(int row,int col,vector<vector<int>>&grid){
        if(row<0 or col<0 or row>=grid.size() or col>=grid[0].size())return 0;
        return 1;
    }
    void island(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&vis){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int currx=row+dirx[i],curry=col+diry[i];
            if(isSafe(currx,curry,grid) and vis[currx][curry]==0 and grid[currx][curry]){
                island(grid,currx,curry,vis);
            }
        }
    }
    
    void subIsland(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&vis,vector<vector<int>>&island,int&flag){
        if(island[row][col]==0)flag=0;
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int currx=row+dirx[i],curry=col+diry[i];
            if(isSafe(currx,curry,grid) and !vis[currx][curry] and grid[currx][curry]){
               subIsland(grid,currx,curry,vis,island,flag);
                
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int grid1Row=grid1.size(),grid1Col=grid1[0].size(),grid2Row=grid2.size(),grid2Col=grid2[0].size();
        vector<vector<int>>islandGrid1(grid1Row,vector<int>(grid1Col,0)),vis(grid2Row,vector<int>(grid2Col,0));
         int flag=0,ans=0;
        for(int i=0;i<grid1Row;i++){
            for(int j=0;j<grid1Col;j++){
                if(islandGrid1[i][j]==0 and grid1[i][j])
                island(grid1,i,j,islandGrid1);
            }
        }
        for(int i=0;i<grid2Row;i++){
            for(int j=0;j<grid2Col;j++){
                if(vis[i][j]==0 and grid2[i][j])
                {
                    flag=1;
                    subIsland(grid2,i,j,vis,islandGrid1,flag);
                    if(flag)ans++;
                }
            }
        }
        return ans;
        
    }
};
