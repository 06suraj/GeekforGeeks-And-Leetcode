class Solution {
public:
    int dp[71][10000];
    int solve(vector<vector<int>>&mat,int target ,int sum,int row)
    {
//    since the minimum abs sum can be 0 , so if we get it , then we will not further explore 
//     this can be further optimised by sorting each row
        if(target==sum and row>=mat.size())return 0;  
        if(row>=mat.size())return abs(sum-target); // boundary condition
        if(dp[row][sum]!=-1)return dp[row][sum];
        int ans=INT_MAX;
        for(int i=0;i<mat[row].size();i++){
            ans=min(ans,solve(mat,target,sum+mat[row][i],row+1));
         }
        dp[row][sum]=ans;
        return dp[row][sum];
        
}
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp,-1,sizeof(dp));
        return(solve(mat,target,0,0));
    }
};
