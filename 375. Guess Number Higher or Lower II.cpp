class Solution {
public:
    
    //SIMPLE MCM
    
    int dp[201][201];
    int solve(int i,int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int  mini=INT_MAX;
        for(int k=i;k<=j;k++){
            mini=min(mini,k+max(solve(i,k-1),solve(k+1,j)));
        }
        return dp[i][j]=mini;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};
