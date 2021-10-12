class Solution {
public:
    int dirx[4]={0,0,1,-1};
    int diry[4]={1,-1,0,0};
    
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int row,int col, int flip){
        if(row<0 or row>=board.size() or col<0 or col>=board[0].size() or board[row][col]=='X' or vis[row][col])return ;
        vis[row][col]=1;
        if(flip)board[row][col]='X';
        for(int i=0;i<4;i++){
            dfs(board,vis,row+dirx[i],col+diry[i],flip);
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' and !vis[0][j])
                dfs(board,vis,0,j,0);
            if(board[n-1][j]=='O' and !vis[n-1][j])
                dfs(board,vis,n-1,j,0);
        }
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' and !vis[i][0])
                dfs(board,vis,i,0,0);
            if(board[i][m-1]=='O' and !vis[i][m-1])
                dfs(board,vis,i,m-1,0);
        }
        
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' and !vis[i][j])
                    dfs(board,vis,i,j,1);
            }
        }
        
        
    }
};
