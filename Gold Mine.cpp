class Solution{
public:
int dp[101][101];
int solve(int i,int j,int n,int m,vector<vector<int>>& M){
    if(i<0 or i>=n or j<0 or j>=m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=(M[i][j]+max(solve(i+1,j+1,n,m,M),max(solve(i,j+1,n,m,M),solve(i-1,j+1,n,m,M))));
    return dp[i][j];
}
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        memset(dp,-1,sizeof(dp));
       int ans=INT_MIN;
       for(int i=0;i<n;i++)ans=max(ans,solve(i,0,n,m,M));
       return ans;
    }
};
