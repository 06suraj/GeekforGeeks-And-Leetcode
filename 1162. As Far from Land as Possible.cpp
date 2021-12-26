class Solution {
public:
    int dirx[4]={0,1,-1,0};
    int diry[4]={1,0,0,-1};
    bool issafe(int x,int y,int n,int m){
        if(x<0 or x>=n or y<0 or y>=m)return 0;
        return 1;
    }
    int maxDistance(vector<vector<int>>& grid) {
      int n=grid.size(),m=grid[0].size();
      queue<pair<int,int>>q;
      vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int i1=0;i1<4;i1++){
                        int currx=i+dirx[i1],curry=j+diry[i1];
                        if(issafe(currx,curry,n,m) and grid[currx][curry]==0)q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            int si=q.size();
            while(si--){
                 auto src=q.front();
                 int currx=src.first,curry=src.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newx=currx+dirx[i],newy=curry+diry[i];
                    if(issafe(newx,newy,n,m) and grid[newx][newy]==0 and vis[newx][newy]==0){q.push({newx,newy});vis[newx][newy]=vis[currx][curry]+1;}
                }
            }
        }
        int ans=-1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               ans=max(ans,vis[i][j]);
            }
        }
        if(ans==0)return -1;
        return ans;
    }
};
