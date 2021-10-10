class Solution {
public:
    int memo[201][201];
    int solve(vector<vector<int>>&grid,int row,int col){
        if(row==grid.size())return 0;
        
        if(col!=-1 and memo[row][col]!=-1)return memo[row][col];
        int ans=INT_MAX;
        for(int i=0;i<grid[row].size();i++)
        {
            if(i!=col){
                ans=min(ans,grid[row][i]+solve(grid,row+1,i));
            }
        }
        if(col!=-1)
        return memo[row][col]=ans;
        else return ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(memo,-1,sizeof(memo));
       return(solve(grid,0,-1));
    }
};
