class coordinate{
    public:
    int x,y;
    coordinate(int x,int y){
        this->x=x;
        this->y=y;
    }
};
class Solution {
public:
    bool destination(int x,int y,int n,int m){
        if(x==n-1 and y==m-1)return 1;
        return 0;
    }
    
    bool isvalid(int n,int m,int x,int y,vector<vector<int>>&vis,vector<vector<int>>&grid){
        if(x<0 or y<0 or x>=n or y>=m or vis[x][y] or grid[x][y]==1)return 0;
        return 1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     int dirx[]={0,0,-1,1,1,-1,-1,1};
     int diry[]={1,-1,0,0,1,-1,1,-1};
      queue<coordinate>q;
    int n=grid.size(),m=grid[0].size();
      vector<vector<int>>vis(n,vector<int>(m,0));
       if(grid[0][0]==1)return -1;
       q.push({0,0});
       vis[0][0]=1;
       while(!q.empty()){
           int si=q.size();
           int curr_x=q.front().x,curr_y=q.front().y;
           if(destination(curr_x,curr_y,n,m))
               return vis[curr_x][curr_y];
           q.pop();
           for(int i=0;i<8;i++){
             int next_x=curr_x+dirx[i],next_y=curr_y+diry[i];
             if(isvalid(n,m,next_x,next_y,vis,grid)){
                q.push({next_x,next_y});
                 vis[next_x][next_y]=vis[curr_x][curr_y]+1;
                }
             }
       }
        return -1;
    }
};
