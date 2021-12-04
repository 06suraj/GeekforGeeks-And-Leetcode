class Solution {
public:
 
  bool isSafe(int x,int y,int n,int m,vector<vector<int>>&vis){
      if(x<0 or x>=n or y<0 or y>=m or vis[x][y])return 0;
      return 1;
  }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            int currx=q.front().first,curry=q.front().second,newx=currx,newy=curry;
            q.pop();
            if(currx==n-1 and curry==m-1)return 1;
            if(grid[currx][curry]==1){
                newy=curry+1,newx=currx;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==3 or dir==5 or dir==1){q.push({newx,newy});vis[newx][newy]=1;}
                }
                newy=curry-1;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==4 or dir==6 or dir==1){q.push({newx,newy});vis[newx][newy]=1;}
                }
            }else if(grid[currx][curry]==2){
                newx=currx+1,newy=curry;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==2 or dir==5 or dir==6){q.push({newx,newy});vis[newx][newy]=1;}
                }
                newx=currx-1;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==2 or dir==3 or dir==4){q.push({newx,newy});vis[newx][newy]=1;}
                }
            }else if(grid[currx][curry]==3){
                newx=currx+1,newy=curry;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==2 or dir==5 or dir==6){q.push({newx,newy});vis[newx][newy]=1;}
                }
                newx=currx,newy=curry-1;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==4 or dir==6 or dir==1){q.push({newx,newy});vis[newx][newy]=1;}
                }
          }
            else if(grid[currx][curry]==4){
                newx=currx+1,newy=curry;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==2 or dir==5 or dir==6){q.push({newx,newy});vis[newx][newy]=1;}
                }
                  newx=currx,newy=curry+1;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==3 or dir==5 or dir==1){q.push({newx,newy});vis[newx][newy]=1;}
                }
            }else if(grid[currx][curry]==5){
                newx=currx-1,newy=curry;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==2 or dir==3 or dir==4){q.push({newx,newy});vis[newx][newy]=1;}
                }
                newx=currx,newy=curry-1;
                 if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==4 or dir==6 or dir==1){q.push({newx,newy});vis[newx][newy]=1;}
                }
           }
            else{
                  newx=currx-1,newy=curry;
                  if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==2 or dir==3 or dir==4){q.push({newx,newy});vis[newx][newy]=1;}
                }
                newy=curry+1,newx=currx;
                if(isSafe(newx,newy,n,m,vis)){
                    int dir=grid[newx][newy];
                    if(dir==3 or dir==5 or dir==1){q.push({newx,newy});vis[newx][newy]=1;}
                }
                
                  
             }
        }
        return 0;
        
    }
};
