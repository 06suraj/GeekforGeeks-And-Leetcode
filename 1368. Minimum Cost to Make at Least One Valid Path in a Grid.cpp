int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};

bool isSafe(int x,int y,vector<vector<int>>&grid,int n,int m){
    if(x<0 or y<0 or x>=n or y>=m or grid[x][y]<1 or grid[x][y]>4)return 0;
    return 1;
}

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> >cost;
       vector<vector<int>>dis(n,vector<int>(m,10000));
       
        //1 . dijkstra which take o(nlogn)
//         cost.push({0,0,0});
//         dis[0][0]=0;
//         while(!cost.empty()){
//             auto temp=cost.top();
//             cost.pop();
//             int cos=temp[0],x1=temp[1],y1=temp[2];
            
//             for(int i=0;i<4;i++){
//                 int  curr_x=x1+dirx[i],curr_y=y1+diry[i];
//                 if(isSafe(curr_x,curr_y,grid,n,m)){
//                     int newcost=cos;
//                     if(grid[x1][y1]-1!=i)newcost++;
//                     if(dis[curr_x][curr_y]>newcost){
//                         // cost.erase(cost.find({dis[curr_x][curr_y],curr_x,curr_y}));
//                         cost.push({newcost,curr_x,curr_y});
//                         dis[curr_x][curr_y]=newcost;
//                     }
//                 }
//             }
            
//         }
        //2. since here possible cost for any move from any cell is only that is remains same(if the direction is same as the move) or cost_to_reach_current_cell+1, so this will reduce our problem to 0-1 bfs (for 0-1 bfs refer https://leetcode.com/discuss/general-discussion/1234074/0-1-bfs) which make our solution to run to o(n) from o(nlogn)
        
        deque<pair<int,int>>q;
        q.push_front({0,0});
        dis[0][0]=0;
        while(!q.empty()){
            int ux=q.front().first,uy=q.front().second,cost=dis[ux][uy];
            q.pop_front();
            for(int i=0;i<=3;i++){
                int vx=ux+dirx[i],vy=uy+diry[i],newcost=1;
                if(isSafe(vx,vy,grid,n,m)){
                    if(grid[ux][uy]-1==i)newcost=0;
                    if(dis[vx][vy]>dis[ux][uy]+newcost){
                    dis[vx][vy]=dis[ux][uy]+newcost;
                    if(newcost)q.push_back({vx,vy});
                    else q.push_front({vx,vy});
                 }
                }
          }
        }
        return dis[n-1][m-1];
    }
};
