class Solution {
public:
    void coordinate(int start,int& x,int& y,int n){
        int row_top=(start-1)/n,col=(start-1)%n;
        
        // since row is considered from bottom , we must subtract with n-1 and due to alternative traversal column value can be extracted according to given condition 
        x=n-1-row_top,y=row_top%2?n-1-col:col;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int>q;
        int vis[n*n+1];
        memset(vis,0,sizeof(vis));
        q.push(1);
        vis[1]=1;
        int ans=1;
        while(!q.empty()){
            int si=q.size();
            for(int j=0;j<si;j++){
                int start=q.front();
                q.pop();
                for(int i=1;i<=6;i++){
                    int next=start+i;
                    int x,y;
                    coordinate(next,x,y,n);
                    if(board[x][y]!=-1)next=board[x][y];
                    if(next==n*n)return ans;
                    if(vis[next]==0){
                        vis[next]=1;
                        q.push(next);
                    }
                    
                }
            }
            ans++;
        }
        return -1;
        
    }
};
