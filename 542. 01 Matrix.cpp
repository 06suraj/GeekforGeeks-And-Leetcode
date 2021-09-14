class Solution {
public:
    int dirx[4]={-1,0,1,0};
    int diry[4]={0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(mat[i][j]==0)
                 {q.push({i,j});
                     vis[i][j]=1;}
            }
        }
        while(!q.empty()){
         int x=q.front().first,y=q.front().second;
            q.pop();
              for(int i=0;i<4;i++){
                  if(dirx[i]+x>=0 and dirx[i]+x<n and diry[i]+y>=0 and diry[i]+y<m and mat[dirx[i]+x][diry[i]+y]==1 and  vis[dirx[i]+x][diry[i]+y]==0){
                      ans[dirx[i]+x][diry[i]+y]=1+ans[x][y];
                      vis[dirx[i]+x][diry[i]+y]=1;
                      q.push({dirx[i]+x, diry[i]+y});
                  }
              }
        }
        return ans;
    }
};
